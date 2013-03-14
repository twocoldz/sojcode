#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
	int t,d;
}cow[100005];

bool cmp(node a,node b)
{
	return a.d*b.t>b.d*a.t;
}

int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		int i;
		long long sum=0,total=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&cow[i].t,&cow[i].d);
			total+=cow[i].d;
		}
		sort(cow+1,cow+1+n,cmp);
		for(i=1;i<=n;i++)
		{
			total-=cow[i].d;
			sum+=(total*2*cow[i].t);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
