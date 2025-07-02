#include<stdio.h>
void WT(int n,int bt[],int wt[])
{
	int i;
	wt[0]=0;
	for(i=1;i<n;i++){
		wt[i]=bt[i-1]+wt[i-1];}
}
void TAT(int n,int bt[],int wt[],int tat[])
{
	int i;
	for(i=0;i<n;i++){
		tat[i]=wt[i]+bt[i];}
}
int main()
{
	int n,i,wt[10],bt[10],tat[10],total_wt=0,total_tat=0;
	printf("enter no of process\n");
	scanf("%d",&n);
	printf("enter burst time of the process\n");
	for(i=0;i<n;i++){
		printf("process %d",i+1);
		scanf("%d",&bt[i]);
		wt[i]=0;
		tat[i]=0;
		}
	WT(n,bt,wt);
	TAT(n,bt,wt,tat);
	printf("process\tburst time\twaiting time\tturnaround time");
	for(i=0;i<n;i++){
		printf("\n%d      \t%d        \t%d        \t       %d         \n",i+1,bt[i],wt[i],tat[i]);
		printf("\n");
		}
	for(i=0;i<n;i++){
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		}
	int avg_wt=total_wt/n;;
	printf("average wt= %d",avg_wt);
	int avg_tat=total_tat/n;
	printf("average tat= %d",avg_tat);
}
