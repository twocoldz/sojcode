#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define min(a,b) a<b?a:b

struct node
{
	int val;
	int pos;
}cow[10005];

bool vis[10005];

bool cmp(node a,node b)
{
	return a.val<b.val;
}

int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		memset(vis,0,sizeof(vis));
		int ans=0;
		int i,j,Mini,Mi=0x7fffffff;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&cow[i].val);
			if(cow[i].val<Mi)
				Mi=cow[i].val;
			cow[i].pos=i;
		}
		sort(cow+1,cow+1+n,cmp);
		for(i=1;i<=n;i++)
		{
			if(cow[i].pos==i)
				continue;
			if(!vis[i])
			{
				int cnt=1;
				int sum=cow[i].val;
				Mini=cow[i].val;
				vis[i]=true;
				j=cow[i].pos;
				while(j!=i)
				{
					cnt++;
					vis[j]=true;
					sum+=cow[j].val;
					if(cow[j].val<Mini)
						Mini=cow[j].val;
					j=cow[j].pos;
				}
				ans+=min(sum+(cnt-2)*Mini,sum+(cnt+1)*Mi+Mini);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}