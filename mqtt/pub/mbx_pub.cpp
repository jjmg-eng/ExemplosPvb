#include "rlmailbox.h"
rlMailbox  mbx_pub("/srv/automation/mbx/mbx_pub.mbx");

int main(){
    char buf[256];
    mbx_pub.read(buf,sizeof(buf));
    printf("-h maqiatto.com -t \"jjmg.engenharia@gmail.com/t01\" -u \"jjmg.engenharia@gmail.com\" -P \"000000\" -p 1883 -i \"uiljljljll\" -m \"%s\"\n",buf);
    return 0;
}
