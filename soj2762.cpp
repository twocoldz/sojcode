#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
	int x,y;
}mon[50005];

bool cmp(node a,node b)
{
	return a.x<b.x;
}

int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&mon[i].x,&mon[i].y);
		}
		sort(mon+1,mon+1+n,cmp);
		int ans=mon[n].y;
		int cnt=1;
		for(i=n-1;i>=1;i--)
		{
			if(mon[i].y>ans)
			{
				cnt++;
				ans=mon[i].y;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
