#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
	int x,y,z;
	/* data */
}peo[100005];

int ordy[100005];
int help[100005];
int n;

bool cmpx(node a,node b)
{
	return a.x>b.x;
}

bool cmpy(int i,int j)
{
	return peo[i].y<peo[j].y;
}

int BinF(int x,int z)
{
	int l=1;
	int r=n,mid;
	while(l<=n)
	{
		mid=(l+r)>>1;
		if(mid<x)
		{
			if(ordy[mid]<z)
			{
				ordy[mid]=z;
			}
			l=mid+1;
		}
		else if(mid>x)
		{
			if(ordy[mid]>z)
				return 0;
			r=mid-1;
		}
		else
		{
			if(ordy[mid]<z)
				ordy[mid]=z;
			return ordy[mid]<=z;
		}
	}
}

int main()
{
	while(scanf("%d",&n)==1&&n)
	{
		int i,ans;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&peo[i].x,&peo[i].y,&peo[i].z);
		}
		sort(peo+1,peo+1+n,cmpx);
		for(i=1;i<=n;i++)
			ordy[i]=i;
		sort(ordy+1,ordy+1+n,cmpy);
		for(i=1;i<=n;i++)
		{
			help[ordy[i]]=i;
		}
		memset(ordy,0,sizeof(ordy));
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(BinF(help[i],peo[i].z))
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}