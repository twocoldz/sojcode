#include <iostream>
#include <cstdio>
#include <cstring>

char m[15005];
char ans[15005];

int main()
{
	int n;
	while(scanf("%d%s",&n,m)==2)
	{
		int t=1;
		while(t<n)
			t=t*10+1;
		int i=0;
		while(true)
		{
			ans[i++]=t/n+'0';
			t%=n;
			if(t==0)
				break;
			t=t*10+1;
		}
		ans[i]='\0';
		if(strcmp(m,ans)==0)
			printf("%d Yes\n",n);
		else
			printf("%d No %s\n",n,ans);
	}
	return 0;
}
