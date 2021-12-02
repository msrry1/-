#include<stdio.h>
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	int a[10001]={0};
	for(i = 1;i <= n;i++)
	{
		a[i]=1;
	}
	for(k = 1;k<=n;k++)
	{
		for(i = 1;i <= n;i++)
		{
			if(i%k==0)
			{
				a[i]=-a[i];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==-1)
		{
			printf("%d ",i);
		}
	}
	return 0;
}
