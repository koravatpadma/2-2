#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    char * myfifo = "helloWorld";
    mkfifo(myfifo, 0666);

    char a1[85], a2[85];
    while (1)
    {
        fd = open(myfifo, O_WRONLY);
        fgets(a2, 85, stdin);
        write(fd, a2, strlen(a2)+1);
        close(fd);
       
        fd = open(myfifo, O_RDONLY);
        read(fd, a1, sizeof(a1));
        printf("User2: %s\n", a1);
        close(fd);
    }
    return 0;
}
