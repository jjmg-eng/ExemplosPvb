#include "rlmailbox.h"
rlMailbox  mbx("/srv/automation/mbx/pushover.mbx");

int main(int argc, char *argv[])
{
    if(argc < 2) 
    	{
    		puts("uso: ntfyDaemon <tópico>");
    		return -1;
    	}
    int buflen;
    unsigned char buf[256+1];

    mbx.read(buf,sizeof(buf));
    printf("pub %s %s\n",argv[1],buf);
    return 0;
}
