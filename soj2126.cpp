#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		
		if(n==-1&&m==-1)
		{
			break;
		}
		int p=1;
		while(p*(p-1)/2<m)
			p++;
		int temp=p*(p-1)/2;
		for(int i=1;i<=n-p;i++)
			printf("%d ",i);
		printf("%d ",n-temp+m);
		for(int i=n;i>=n-p+1;i--)
		{
			if(i!=n-temp+m)
				printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}