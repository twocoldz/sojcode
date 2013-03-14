#include <iostream>
#include <cstring>
#include <cstdio>

int main()
{
	char a[10];
	int b[10]={9,7,3,9,7,3,9};
	int t,cases=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		int i,k,sum=0,temp=(strlen(a)-6)^1;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='?')
			{
				k=i;
				continue;
			}
			sum+=(a[i]-'0')*b[i+temp];
		}
		i=0;
		while((sum+b[k+temp]*i)%10)
			i++;
		a[k]=i+'0';
		printf("Scenario #%d:\n",cases++);
		printf("%s\n",a);
		printf("\n");
	}
}