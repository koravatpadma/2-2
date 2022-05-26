#include<stdio.h>
#include<unistd.h>
int main() {
	int pipefd[2];
	int rtstatus;
	char wrtmsg[3][20]={"Hello", "BVRIT","Students"};
	char rdmsg[20];
	rtstatus = pipe(pipefd);
	if (rtstatus == -1) {
		printf("Pipe is not created\n");
		return 1;
	}
	printf("Writing to pipe: %s\n", wrtmsg[0]);
	write(pipefd[1], wrtmsg[0], sizeof(wrtmsg[0]));
	read(pipefd[0], rdmsg, sizeof(rdmsg));
	printf("Reading from pipe: %s\n", rdmsg);
	printf("Writing to pipe: %s\n", wrtmsg[1]);
	write(pipefd[1], wrtmsg[1], sizeof(wrtmsg[1]));
	read(pipefd[0], rdmsg, sizeof(rdmsg));
	printf("Reading from pipe: %s\n", rdmsg);
	printf("Writing to pipe: %s\n", wrtmsg[2]);
	write(pipefd[1], wrtmsg[2], sizeof(wrtmsg[2]));
	read(pipefd[0], rdmsg, sizeof(rdmsg));
	printf("Reading from pipe: %s\n", rdmsg);
	return 0;
}

