#include<stdio.h>
#include<stdlib.h>
typedef struct paiming{
    int id;
    int score;
    int leval;
}peo;
int inc(const void *a,const void *b)
{
    return (*(peo*)a).score - (*(peo*)b).score;             //��c���Ա�д��������������һ��ѡ�ֲμӱ����������Ĺ��������÷�Խ�ߣ�����Խ�͡������������ʱ��Ҫ���ֳ�����ѡ�ֵĳ���˳���������÷ֺ�������Σ������ͬ������ѡ�־�����ͬ�����Σ�����������ţ����ÿ���ͬ���ε�ѡ��������
}
                                                            // ���磺
                                                            // ѡ����ţ� 1��2��3��4��5��6��7
                                                            // ѡ�ֵ÷֣� 5��3��4��7��3��5��6
                                                            // �������Ϊ��3��1��2��5��1��3��4
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
    printf("���  �÷�  ����\n");
    for(i = 0; i < n; i++)
    {
        printf("%-4d %-4d %-4d\n",a[i].id,a[i].score,a[i].leval);
    }
    return 0;
}