#include<stdio.h>
int main()
{
	int n,m,i,j,k,sum=0;
	int x1,x2,x3,x4,y1,y2,y3,y4;
	scanf("%d%d",&n,&m);
	int a[100][1001]={0};
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int q;
	scanf("%d",&q);
	for(k=0;k<q;k++)
	{
		scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(i<=x2 && j<=y2)
				{
					sum+=a[i][j];
				}
				if(i>=x3 && j>=y3)
				{
					sum+=a[i][j];
				}
			}
		}
		if(x2==x3 && y2==y3)
		{
			sum-=a[x2][y2];
		}
		printf("%d ",sum);
	}
	return 0;
 } 
