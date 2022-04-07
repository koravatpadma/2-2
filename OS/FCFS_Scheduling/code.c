#include<stdio.h>
int main(){
    int n,p[20],wt[20],tat[20],i,twt=0,ttat=0;
    float avg_wt,avg_tat;
   
    printf("No.of processors: ");
    scanf("%d",&n);
    printf("assign Burst time for each processor\n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    wt[0] = 0;
    for(i=0;i<n;i++){
        tat[i] = wt[i] + p[i];
        wt[i+1] = tat[i];
        twt += wt[i];
        ttat += tat[i];
    }
    avg_wt = twt / (float)n;
    avg_tat = ttat / (float)n;
    printf("processor  BurstTime  WaitingTime  TurnAroundTime\n");
    for(i=0;i<n;i++){
        printf("    %d          %d          %d          %d\n",(i+1),p[i],wt[i],tat[i]);
    }
    printf("Average waiting time is: %.2f\nAverage Turn Around Time is: %.2f",avg_wt,avg_tat);
     
    return 0;
}
