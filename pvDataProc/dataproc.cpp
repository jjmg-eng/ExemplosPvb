#include "dataproc.h"

int main(){
    int I1, I2;
    setup();
    
    while(1){
        const char *s=mbox.read(0);
        if(s[0]){
            sscanf(s,"%d;%d",&I1, &I2);
            shmData.F1 = I1 / 100.0;
            shmData.F2 = I2 / 100.0;
            printf("%g / %g\n", shmData.F1, shmData.F2);
            SHMWRITE;
            
            sprintf(buf,"insert %s values (now(3),%g,%g)", tableName, shmData.F1, shmData.F2);
            db.dbQuery(buf);
        }
	rlsleep(10);
    }
    return 0;
}

void setup()
{
    int i,j;
    
    mbox.clear();

    db.open("QMYSQL","localhost","pvdb","pvbrowser","pvbrowser");

    i=sprintf(buf,"create table if not exists %s (t timestamp(3)",tableName);
    for (j=0; j<2; j++) i+=sprintf(&buf[i],",F%d float", j+1);
	i+=sprintf(&buf[i],");"); buf[i]=0;
	db.dbQuery(buf);

    i=sprintf(buf,"show indexes from %s;", tableName);
    db.dbQuery(buf);

    if( !db.result->numRowsAffected() ){
        i=sprintf(buf,"create index idx_%s on %s(t);",tableName, tableName);
        db.dbQuery(buf);	
    }
}
