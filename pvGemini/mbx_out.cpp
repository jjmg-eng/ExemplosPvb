#include "rlmailbox.h"
rlMailbox  mbx_out("/srv/automation/mbx/mbx_out.mbx");

int main(){
    char s[4096];
    mbx_out.clear();
    while(1){
        fgets(s,4096,stdin);
        printf("%s",s);
        mbx_out.write(s);
    }
    return 0;
}
