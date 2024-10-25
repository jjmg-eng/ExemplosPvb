#include "rlmailbox.h"
rlMailbox  mbx("/srv/automation/mbx/pushover.mbx");

int main(int argc, char *argv[])
{
    if(argc < 2){
    	printf("uso: %s <tópico>\n",argv[0]);
    	return -1;
    }
    char buf[256];
    mbx.read(buf,sizeof(buf));
    printf("-d \"%s\" ntfy.sh/%s\n",buf,argv[1]);
    return 0;
}
