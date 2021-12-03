#include<stdio.h>
#include<string.h> 
int longestPalindrome(char * s){
    int a[128] = {0};
    int ns = strlen(s);
    int max=0;
    int sum=0,i,ans=0;
    for(i = 0;i < ns;i++)
    {
        a[s[i]]++;
    }
    for(i = 0;i < 128;i++)
    {
    	if(a[i]%2)
		{
			ans=1;
			a[i]=a[i]/2*2;
		} 
		
    }
    for(i = 0;i < 128;i++)
    {
        sum+=a[i];
    }
    return sum+ans;
}
int main()
{
	char s[1020];
	gets(s);
	printf("%d",longestPalindrome(s));
	return 0; 
}
