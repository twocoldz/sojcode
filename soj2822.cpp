#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

struct node
{
	int l,r;
	int num;
}tree[200005*4];

int pos[200005];
int val[200005];
int fia[200005];

void BuildTree(int k,int l,int r)
{
	tree[k].l=l;
	tree[k].r=r;
	tree[k].num=r-l+1;
	if(l==r)
	{
		return;
	}
	int mid=(l+r)>>1;
	BuildTree(k*2,l,mid);
	BuildTree(k*2+1,mid+1,r);
}

int Insert(int k,int l,int r,int x,int val)
{
	if(l==r)
	{
		tree[k].num--;
		fia[l]=val;
		return 0;
	}
	int mid=(l+r)>>1;
	if(tree[k*2].num>=x)
	{
		Insert(k*2,l,mid,x,val);
	}
	else
	{
		Insert(k*2+1,mid+1,r,x-tree[k*2].num,val);
	}
	tree[k].num=tree[k*2].num+tree[k*2+1].num;
}

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&pos[i],&val[i]);
		}
		BuildTree(1,1,n);
		for(i=n;i>0;i--)
		{
			Insert(1,1,n,pos[i]+1,val[i]);
		}
		for(i=1;i<=n;i++)
		{
			i==n?printf("%d\n",fia[i]):printf("%d ",fia[i]);
		}
	}
	return 0;
}