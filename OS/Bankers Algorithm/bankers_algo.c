#include <stdio.h>

int main() {
    int r,c,i,j,k;
    printf("Enter no. of rows and columns");
    scanf("%d%d",&r,&c);
    printf("Enter allocated matrix");
    int alloc[r][c];
    for(i=0;i<r;i++){
    	for(j=0;j<c;j++){
    		scanf("%d",&alloc[i][j]);
    	}
    }
     printf("Enter max matrix");
    int max[r][c];
    for(i=0;i<r;i++){
    	for(j=0;j<c;j++){
    		scanf("%d",&max[i][j]);
    	}
    }
     printf("Enter available resources");		
    int available[c];
    for(j=0;j<c;j++){
    	scanf("%d",&available[j]);
    }	
    int fin[r],ans[r],ind=0;
    for(k=0;k<r;k++){
    	fin[k] = 0;
    }
    int need[r][c];
    for(i=0;i<r;i++){
    	for(j=0;j<c;j++){
    		need[i][j] = max[i][j] - alloc[i][j];
    	}
    }
    int y=0;
    for(k=0;k<r;k++){
    	for(i=0;i<r;i++){
    	    if(fin[i]==0){
    		int flag=0;
    		for(j=0;j<c;j++){
    		     if(need[i][j] > available[j]){
    			  flag=1;
    			  break;
    		       }
    		}
    	       	if(flag==0){
    			    ans[ind++]=i;
    			    for(y=0;y<c;y++)
    			 	available[y] += alloc[i][y];
    			   fin[i] = 1;
    		       }
    	   }
    	}
    }
    int flag=1;
    for(int i=0;i<r;i++){
    	if(fin[i]==0){
    		flag=0;
    		printf("System is not safe");
    		break;
    	}
    }
    if(flag==1){
    	printf("Safe sequence of processes :\n");
    	for(i=0;i<r-1;i++)
    		printf("P%d -> ",ans[i]);
    	printf("P%d",ans[r-1]);
    }
    return 0;
   } 													
    	
