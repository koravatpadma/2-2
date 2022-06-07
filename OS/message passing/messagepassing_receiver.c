#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
  

struct mesg_buffer {
    long msg_type;
    char msg_text[100];
} msg;
  
int main()
{
    key_t key;
    int msgid;
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msgrcv(msgid, &msg, sizeof(msg), 1, 0);
    printf("Data Received is : %s \n", msg.msg_text);
    msgctl(msgid, IPC_RMID, NULL);
  
    return 0;
}
