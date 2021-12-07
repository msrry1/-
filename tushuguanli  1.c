#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct books{
	char name[50];
	char author[10];
	int price;
	struct books *next;
}book;
void add(book *head)
{
	book *p = (book*)malloc(sizeof(book));
	printf("������������������۸�\n");
	scanf("%s%s%d",p->name,p->author,&p->price);
	if(head->next == NULL)
	{
		head->next = p;
		p->next = NULL;
	}
	else
	{
		p->next = head->next;
		head->next = p;
	}
}
void del(book *head)
{
	if(head->next ==NULL)
	{
		printf("�����û���鼮\n");
		return;
	}
	char delname[10];
	printf("������Ҫɾ��������\n");
	scanf("%s",delname);
	book *p = head->next;
	book *q = NULL;
	while(p != NULL && (strcmp(p->name,delname) != 0))
	{
		q = p;
		p = p->next;
	}
	if(p == NULL)
	{
		printf("��Ǹ��û���ҵ�\n");
		return;
	}
	q->next = p->next;
}
void update(book *head)
{
	int n;
	if(head->next ==NULL)
	{
		printf("�����û���鼮\n");
		return;
	}
	char upname[10];
	printf("������Ҫ�޸���Ϣ������\n");
	scanf("%s",upname);
	book *q = head->next;
	book *p = NULL;
	while(q != NULL && strcmp(q->name,upname) != 0)
	{
		p = q;
		q = q->next;
	}
	if(q == NULL)
	{
		printf("��Ǹ��û���ҵ�\n");
		return;
	}
	printf("�޸���������1���޸ļ۸�����2\n");
	scanf("%d",&n);
	if(n == 1 || n == 2)
	{
		if(n == 1)
		{
			printf("�������޸ĺ������\n");
			scanf("%s",q->name);
		}
		else
		{
			printf("�������޸ĺ�ļ۸�\n");
			scanf("%d",&q->price);
		}
	}
	else
	{
		printf("�밴Ҫ���������\n");
	} 
}
void search(book *head)
{
	int n;
	if(head->next ==NULL)
	{
		printf("�����û���鼮\n");
		return;
	}
	char sename[10];
	printf("������Ҫ��ѯ��Ϣ������\n");
	scanf("%s",sename);
	book *p = head;
	book *q = NULL;
	while(p != NULL && strcmp(p->name,sename) != 0)
	{
		q = p;
		p = p->next;
	}
	if(p == NULL)
	{
		printf("��Ǹ��û���ҵ�\n");
		return;
	}
	printf("������%s\n���ߣ�%s\n�۸�%d\n",p->name,p->author,p->price);
}
void show(book *head)
{
	book *p = head->next;
	while(p)
	{
		printf("������%s\n���ߣ�%s\n�۸�%d\n",p->name,p->author,p->price);
		p = p->next;
	}
}
void sort(book *head)
{
	int tprice;
	char tname[50];
	char tauthor[50];
	book *p = head;
	book *q = head;
	if(head->next == NULL)
	{
		printf("����Ϊ���޷�����\n");
		return; 
	}
	if(head->next->next == NULL)
	{
		printf("������ֻ��һ��Ԫ��\n");
		return; 
	}
	if(head->next->next->next == NULL)
	{
		p = head->next;
		q = head->next->next;
		if(p->price > q->price)
		{
			tprice = q->price;
			q->price = p->price;
			p->price = tprice;
				
			strcpy(tname,q->name);
			strcpy(q->name,p->name);
			strcpy(p->name,tname);
			
			strcpy(tauthor,q->author);
			strcpy(q->author,p->author);
			strcpy(p->author,tauthor);
			return;
		}
	}	
	for(p = head->next;p->next!= NULL;p = p->next)
	{
		for(q = p->next;q != NULL;q = q->next)
		{
			if(p->price > q->price)
			{
				tprice = q->price;
				q->price = p->price;
				p->price = tprice;
				
				strcpy(tname,q->name);
				strcpy(q->name,p->name);
				strcpy(p->name,tname);
				
				strcpy(tauthor,q->author);
				strcpy(q->author,p->author);
				strcpy(p->author,tauthor);
			}
		}
	}
	printf("���������\n");
}
int main()
{
	int n;
	book *head=(book*)malloc(sizeof(book));
	head->next = NULL;
	while(1)
	{
		printf("\n\n\n-1�˳�\n1.�����鼮\n2.ɾ���鼮\n3.�޸��鼮\n4.��ѯ�鼮\n5.��ʾ�����鼮\n6.����\n\n\n");
		scanf("%d",&n);
		if(n == -1)
		{
			break;
		}
		switch(n)
		{
			case 1:add(head);break;
			case 2:del(head);break;
			case 3:update(head);break;
			case 4:search(head);break;
			case 5:show(head);break;
			case 6:sort(head);break;
		}
	}
	return 0;
}
