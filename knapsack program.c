#include<stdio.h>

int max(int a,int b)
{
return (a>b)?a:b;
}

int main()
{
int n,i,j,w;

printf("Enter number of items: ");
scanf("%d",&n);

int weight[n],profit[n];

printf("Enter weights:\n");
for(i=0;i<n;i++)
scanf("%d",&weight[i]);

printf("Enter profits:\n");
for(i=0;i<n;i++)
scanf("%d",&profit[i]);

printf("Enter capacity of knapsack: ");
scanf("%d",&w);

int dp[n+1][w+1];

for(i=0;i<=n;i++)
{
for(j=0;j<=w;j++)
{
if(i==0||j==0)
dp[i][j]=0;
else if(weight[i-1]<=j)
dp[i][j]=max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
else
dp[i][j]=dp[i-1][j];
}
}

printf("\nMaximum Profit = %d\n",dp[n][w]);

printf("\nFinal DP Table:\n");

for(i=0;i<=n;i++)
{
for(j=0;j<=w;j++)
{
printf("%d\t",dp[i][j]);
}
printf("\n");
}

return 0;
}
