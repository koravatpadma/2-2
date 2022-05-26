#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdlib.h>
char* m1 = "hello";
char* m2 = "BVRITH";
char* m3 = "Students";

int main()
{
	char buf[16];
	int p[2], i,pid;

	if (pipe(p)==-1){
	     printf("pipe not created\n");
	     return 1;
	}
	pid=fork();
	
 
       if(pid>0){
	    write(p[1], m1, sizeof(buf));
	    printf("writing to  pipe:%s\n", m1);
	    write(p[1], m2,  sizeof(buf));
	    printf("writing to pipe:%s\n", m2);
	    write(p[1], m3,  sizeof(buf));
	    printf("writing to pipe:%s\n", m3);
	
	wait(NULL);
      }
      else{
   
	  //	for (i = 0; i < 3; i++) {
		/* read pipe */
	    while(i=read(p[0], buf,sizeof(buf))>0)
	      	printf("reading from pipe:%s\n", buf);
		 
         // if (i!= 0)
          //  exit(2);
       // printf("Finished reading\n");
    
  }
	
	return 0;
}
