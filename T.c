#include<stdio.h>
int main()
{	
int AT[10], BT[10], RT[10] , WAITING_TIME=0, TURNAROUND_TIME=0;
int TIME_QUANTUM , FLAG=0 , COUNT , J , N , TIME , REMAIN ;
printf("PLEASE ENTER THE TOTAL NO OF PROCESSES YOU WANT TO COMPUTE:\t ");
scanf("%d", &N);
REMAIN=N;
for(COUNT=0;COUNT<N;COUNT++)
{
printf("Enter Arrival Time and Burst Time for Process Number %d :",COUNT+1);
scanf("%d",&AT[COUNT]);
scanf("%d",&BT[COUNT]);
RT[COUNT]=BT[COUNT];
}
printf("PLEASE ENTER TIME QUANUTM YOU WANT TO KEEP:\t");
scanf("%d",&TIME_QUANTUM);
printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
for(TIME=0,COUNT=0;REMAIN!=0;)
{
if(RT[COUNT]<=TIME_QUANTUM && RT[COUNT]>0)
{
TIME+=RT[COUNT];
RT[COUNT]=0;
FLAG=1;
}
else if(RT[COUNT]>0)
{
RT[COUNT]-=TIME_QUANTUM;
TIME+=TIME_QUANTUM;
}
if(RT[COUNT]==0 && FLAG==1)
{
REMAIN--;
printf("P[%d]\t|\t%d\t|\t%d\n",COUNT+1,TIME-AT[COUNT],TIME-AT[COUNT]-BT[COUNT]);
WAITING_TIME+=TIME-AT[COUNT]-BT[COUNT];
TURNAROUND_TIME+=TIME-AT[COUNT];
FLAG=0;
}
if(COUNT==N-1)
COUNT=0;
else if(AT[COUNT+1]<=TIME)
COUNT++;
else
COUNT=0;
}
printf("\nHERE THE AVERAGE WAITING TIME= %f\n",WAITING_TIME*1.0/N);
printf("HERE THE AVERAGE TURNAROUND TIME = %f",TURNAROUND_TIME*1.0/N);
return 0;
}
