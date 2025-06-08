#include "rlmailbox.h"
rlMailbox  mbx_in("/srv/automation/mbx/mbx_in.mbx");

int main(){
    char buf[256];
    while(1){
        mbx_in.read(buf,sizeof(buf));
        printf("%s\n",buf);
        fflush(stdout);
    }
    return 0;
}
