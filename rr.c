#include<stdio.h>
void main()
{
	int n,i,at[10],bt[10],wt[10],tat[10],completed=0,quantum,rem_bt[10],time=0;
	int total_wt=0,total_tat=0;
	printf("enter the no of process\n");
	scanf("%d",&n);
	printf("enter the arrival time and burst time of process\n");
	for(i=0;i<n;i++){
		printf("AT %d",i+1);
		scanf("%d",&at[i]);
		printf("BT %d",i+1);
		scanf("%d",&bt[i]);
		rem_bt[i]=bt[i];
		}
	printf("enter the time quantum\n");
	scanf("%d",&quantum);
	while(completed<n)
	{
		for(i=0;i<n;i++)
		{
			if((at[i]<=time)&&(rem_bt[i]>0))
			{
				if(rem_bt[i]<=quantum)
				{
					time=time+rem_bt[i];
					tat[i]=time-at[i];
					wt[i]=tat[i]-bt[i];
					rem_bt[i]=0;
					completed++;
				}
				else
				{
					rem_bt[i]=rem_bt[i]-quantum;
					time=time+quantum;
				}
			}
		}
	}
	printf("process\tAT\tBT\tWT\tTAT\n");
	for(i=0;i<n;i++){
		printf("%7d\t%2d\t%2d\t%2d\t%3d\n",i+1,at[i],bt[i],wt[i],tat[i]);
		printf("\n");
	}
	for(i=0;i<n;i++){
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		}
	int avg_wt=total_wt/n;
	int avg_tat=total_tat/n;
	printf("average wt=%d",avg_wt);
	printf("average tat=%d",avg_tat);
}
