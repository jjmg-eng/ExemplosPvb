#include "rlmailbox.h"
rlMailbox  mailbox("/srv/automation/mbx/mbx_daemon.mbx");

int main(){
    char s[1024];
    mailbox.clear();
    while(1){
        fgets(s,1024,stdin);
        printf("%s",s);
        mailbox.write(s);
    }
    return 0;
}
