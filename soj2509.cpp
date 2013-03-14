#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 500000000

int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		int i,a,b,min=maxn,sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			sum+=(a>b?a:b);
			if(a<min)
			{
				min=a;
			}
		}
		sum+=min;
		printf("%d\n",sum);
	}
	return 0;
}
