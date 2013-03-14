#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

struct node
{
	int s,g;
}pro[22];

bool cmp(node a,node b)
{
	return min(a.g,b.s)>min(b.g,a.s);
}

int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&pro[i].s);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&pro[i].g);
		}
		sort(pro+1,pro+1+n,cmp);
		int sum=0,t=0;
		for(i=1;i<=n;i++)
		{
			t+=pro[i].s;
			sum=max(sum,t)+pro[i].g;
		}
		printf("%d\n",sum);
	}
	return 0;
}