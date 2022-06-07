#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 50  

struct msg_buffer {
    long msg_type;
    char msg_text[100];
} msg;
  
int main()
{
    key_t key;
    int msgid;
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msg.msg_type = 1;
    printf("Write Data : ");
    fgets(msg.msg_text,MAX,stdin);
    msgsnd(msgid, &msg, sizeof(msg), 0);
    printf("Data send is : %s \n", msg.msg_text); 
    return 0;
}

