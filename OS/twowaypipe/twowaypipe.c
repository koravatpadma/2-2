#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdlib.h>


int main()
{
    char* m1="Hello";
    char* m2="BVRITH";
  
	char buf[16];
	int p1[2],p2[2], i,pid;

	if (pipe(p1)==-1){
	 printf("pipe1 not created\n");
	 return 1;
	}
	if (pipe(p2)==-1){
	 printf("pipe2 not created\n");
	 return 1;
	}
	
   /*  printf("enter m1,m2 and m3");
     scanf("%s%s%s",m1,m2,m3);
      printf("%s%s%s",m1,m2,m3);*/
     pid=fork();
 
 if(pid!=0){
     close(p1[0]);
     close(p2[1]);
     printf("writing to  pipe:%s\n", m1);
	 write(p1[1], m1, sizeof(buf));
	// printf("writing to  pipe:%s\n", m1);
	 read(p2[0], buf,sizeof(buf));
	 printf("reading from pipe:%s\n", buf);
/* write(p[1], m2,  sizeof(buf));
	printf("writing to pipe:%s\n", m2);
	write(p[1], m3,  sizeof(buf));
	printf("writing to pipe:%s\n", m3);*/
	
	//wait(NULL);
 }
 else{
     close(p1[1]);
     close(p2[0]);
     read(p1[0], buf,sizeof(buf));
	 printf("reading from pipe:%s\n", buf);
	 write(p2[1], m2, sizeof(buf));
	 printf("writing to  pipe:%s\n", m2);
	  //	for (i = 0; i < 3; i++) {
		/* read pipe */
//	while(i=read(p[0], buf,sizeof(buf))>0)
	//	printf("reading from pipe:%s\n", buf);
	

		
         // if (i!= 0)
          //  exit(2);
       // printf("Finished reading\n");
    
    
  }
	
	return 0;
}
