#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define max(a,b) a>b?a:b

using namespace std;

struct node
{
	int l,r,mid;
	int v,p;
}tree[5010];

struct point
{
	int x,y;
}num[505];

struct expoint
{
	int y,v;
	int l,r;
}help[1010];

bool cmp(expoint a,expoint b)
{
	if(a.y==b.y)
		return a.v>b.v;
	return a.y<b.y;
}

int pos[1010];
int n,c,len;

int BinF(int x)
{
	int l=1;
	int r=len;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(pos[mid]==x)
			return mid;
		else if(pos[mid]>x)
			r=mid-1;
		else
			l=mid+1;
	}
}

void BuildTree(int l,int r,int u)
{
	int mid=(l+r)>>1;
	tree[u].l=l;
	tree[u].r=r;
	tree[u].mid=mid;
	tree[u].v=0;
	tree[u].p=0;
	if(l==r)
		return;
	BuildTree(l,mid,u<<1);
	BuildTree(mid+1,r,(u<<1)+1);
}

void Modify(int l,int r,int u,int x)
{
	int mid=tree[u].mid;
	if(tree[u].l==l&&tree[u].r==r)
	{
		tree[u].p+=x;
		tree[u].v+=x;
		return;
	}
	if(tree[u].p!=0)
	{
		tree[u<<1].p+=tree[u].p;
		tree[(u<<1)+1].p+=tree[u].p;
		tree[u<<1].v+=tree[u].p;
		tree[(u<<1)+1].v+=tree[u].p;
		tree[u].p=0;
	}
	if(r<=mid)
		Modify(l,r,u<<1,x);
	else if(l>mid)
		Modify(l,r,(u<<1)+1,x);
	else
	{
		Modify(l,mid,u<<1,x);
		Modify(mid+1,r,(u<<1)+1,x);
	}
	tree[u].v=max(tree[u<<1].v,tree[(u<<1)+1].v);
}

bool IsCan(int e)
{
	int i;
	for( i=1;i<=n;i++)
	{
		pos[i]=num[i].x;
		pos[i+n]=num[i].x+e-1;

		help[i].y=num[i].y;
		help[i].l=num[i].x;
		help[i].r=num[i].x+e-1;
		help[i].v=1;

		help[i+n].y=num[i].y+e-1;
		help[i+n].l=num[i].x;
		help[i+n].r=num[i].x+e-1;
		help[i+n].v=-1;
	}

	sort(pos+1,pos+n*2+1);
	sort(help+1,help+n*2+1,cmp);

	len=unique(pos+1,pos+n*2+1)-(pos+1);
	BuildTree(1,len,1);
	
	for( i=1;i<=2*n;i++)
	{
		int l=BinF(help[i].l);
		int r=BinF(help[i].r);
		Modify(l,r,1,help[i].v);
		if(tree[1].v>=c)
			return true;
	}
	return false;
}

int main()
{
	while(scanf("%d %d",&c,&n)==2&&(c||n))
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&num[i].x,&num[i].y);
		}
		int l=1,r=10000;
		int ans;
		while(l<=r)
		{
			int mid=(r+l)>>1;
			if(IsCan(mid))
			{
				ans=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}