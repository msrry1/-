#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> 
void fanzhuan(char *a,int n)
{
	char t;
	int i;
	for(i = 0;i < n/2;i++)
	{ 
	    t = a[i];
	    a[i] = a[n-1-i];
	    a[n-1-i] = t;
	}      
}
int main(void)
{
	int t = 0,i;
	char n = '0';
   	char a[10001] = {0},b[10001] = {0},c[10001] = {0};
   	gets(a);
   	gets(b);
   	int len1 = strlen(a);
   	int len2 = strlen(b);
   	int len = fmax(len1,len2);
   	fanzhuan(a,len1);
   	fanzhuan(b,len2);
   	if(len1 < len2)
	{
   	  	for(i = len1;i < len2;i++)
   	 	{
   	 		a[i] = '0';
		}
	}
   else
   	{
   		for(i = len2;i < len1;i++)
   		{
   			b[i] = '0';
		}
   	}
   	for(i = 0;i < len;i++)
	{ 
     	c[i] = a[i] + b[i] + t - '0';
     	t = (c[i] - '0')/10;
     	c[i] = (c[i] - '0')%10 + '0';
   	} 
   	if(t)
   	{
   		c[len] = '1';
   		for(i = len;i >= 0;i--)
   		{
   			printf("%c",c[i]);
	   	}
	   	return 0;
   	}
   	else
   	{
   		for(i = len-1;i >= 0;i--)
   		{
   			printf("%c",c[i]);
		}
   	}
   	return 0;
}
