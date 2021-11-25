#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,a[1000][1000] = {0},j;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < i + 1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i = 1;i < n;i++)
    {
        a[i][0] += a[i-1][0];
        a[i][i] += a[i-1][i-1];
    }
    int max = a[0][0];
    for(i = 1;i < n;i++)
    {
        for(j = 0;j < i+1;j++)
        {
            if(j != 0 && j != i)
            {
                a[i][j] += fmax(a[i-1][j-1],a[i-1][j]);
            }
            max = fmax(max,a[i][j]);
        }
    }
    printf("%d",max);
    return 0;
}
