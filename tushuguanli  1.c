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
	printf("请输入书名，作者与价格\n");
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
		printf("书库中没有书籍\n");
		return;
	}
	char delname[10];
	printf("请输入要删除的书名\n");
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
		printf("抱歉，没有找到\n");
		return;
	}
	q->next = p->next;
}
void update(book *head)
{
	int n;
	if(head->next ==NULL)
	{
		printf("书库中没有书籍\n");
		return;
	}
	char upname[10];
	printf("请输入要修改信息的书名\n");
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
		printf("抱歉，没有找到\n");
		return;
	}
	printf("修改作者输入1，修改价格输入2\n");
	scanf("%d",&n);
	if(n == 1 || n == 2)
	{
		if(n == 1)
		{
			printf("请输入修改后的作者\n");
			scanf("%s",q->name);
		}
		else
		{
			printf("请输入修改后的价格\n");
			scanf("%d",&q->price);
		}
	}
	else
	{
		printf("请按要求进行输入\n");
	} 
}
void search(book *head)
{
	int n;
	if(head->next ==NULL)
	{
		printf("书库中没有书籍\n");
		return;
	}
	char sename[10];
	printf("请输入要查询信息的书名\n");
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
		printf("抱歉，没有找到\n");
		return;
	}
	printf("书名：%s\n作者：%s\n价格：%d\n",p->name,p->author,p->price);
}
void show(book *head)
{
	book *p = head->next;
	while(p)
	{
		printf("书名：%s\n作者：%s\n价格：%d\n",p->name,p->author,p->price);
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
		printf("链表为空无法排序\n");
		return; 
	}
	if(head->next->next == NULL)
	{
		printf("链表中只有一个元素\n");
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
	printf("排序已完成\n");
}
int main()
{
	int n;
	book *head=(book*)malloc(sizeof(book));
	head->next = NULL;
	while(1)
	{
		printf("\n\n\n-1退出\n1.增加书籍\n2.删除书籍\n3.修改书籍\n4.查询书籍\n5.显示所有书籍\n6.排序\n\n\n");
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
