#include "rlmailbox.h"
rlMailbox  mbx_sub("/srv/automation/mbx/mbx_sub.mbx");

int main(){
    char s[1024];
    mbx_sub.clear();
    while(1){
        fgets(s,1024,stdin);
        printf("%s",s);
        mbx_sub.write(s);
    }
    return 0;
}
