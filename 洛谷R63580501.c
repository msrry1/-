#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,na,count = 0;
    char a[101] = {'0'};
    scanf("%d",&n);
    scanf("%s",a);
    na = strlen(a);
    for(i = 0;i < na-1;i++)
    {
        if(a[i] == 'V' && a[i+1] == 'K')
        {
            count++;
            a[i] = 'x';
            a[i+1] = 'x';
        }
    }
    for(i = 0;i < na-1;i++)
    {
        if((a[i] == 'K' && a[i+1] =='K') || (a[i] == 'V' && a[i+1] == 'V'))
        {
            count++;
            break;
        }
    }
    printf("%d",count);
    return 0;
}