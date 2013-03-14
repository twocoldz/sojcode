#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int cas;
	char c;
	cin>>cas;
	while(cas--)
	{
		int a,n,sum=0;
		c=getchar();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			sum+=a;
		}
		if(sum%n==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}