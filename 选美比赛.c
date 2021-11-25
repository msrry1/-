#include<stdio.h>
#include<stdlib.h>
typedef struct paiming{
    int id;
    int score;
    int leval;
}peo;
int inc(const void *a,const void *b)
{
    return (*(peo*)a).score - (*(peo*)b).score;             //用c语言编写软件完成以下任务：一批选手参加比赛，比赛的规则是最后得分越高，名次越低。当半决赛结束时，要在现场按照选手的出场顺序宣布最后得分和最后名次，获得相同分数的选手具有相同的名次，名次连续编号，不用考虑同名次的选手人数。
}
                                                            // 例如：
                                                            // 选手序号： 1，2，3，4，5，6，7
                                                            // 选手得分： 5，3，4，7，3，5，6
                                                            // 输出名次为：3，1，2，5，1，3，4
int inc1(const void *a,const void *b)
{
    return (*(peo*)a).id -(*(peo*)b).id;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    peo *a =(peo*)malloc(n * sizeof(peo));
    for(i = 0; i < n; i++)
    {
        scanf("%d%d",&a[i].id,&a[i].score);
        a[i].leval = 0;
    }
    qsort(a,n,sizeof(a[0]),inc);
    a[0].leval = 1;
    for(i = 0; i < n-1; i++)
    {
        if(a[i].score == a[i+1].score)
        {
            a[i+1].leval = a[i].leval;  
        }
        else
        {
            a[i+1].leval = a[i].leval + 1;
        }
    }
    qsort(a,n,sizeof(a[0]),inc1);
    printf("序号  得分  排名\n");
    for(i = 0; i < n; i++)
    {
        printf("%-4d %-4d %-4d\n",a[i].id,a[i].score,a[i].leval);
    }
    return 0;
}