#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
	int l,r;
	int lazy;
	int c;
}tree[100005*4];

void BuildTree(int k,int l,int r)
{
	tree[k].l=l;
	tree[k].r=r;
	tree[k].c=1;
	tree[k].lazy=0;
	if(l==r)
	{
		return;
	}
	int mid=(l+r)>>1;
	BuildTree(k*2,l,mid);
	BuildTree(k*2+1,mid+1,r);
}

int ans;

void Query(int k,int l,int r)
{
	if(tree[k].l>=l&&tree[k].r<=r)
	{
		ans=ans|tree[k].c;
		return;
	}
	if(tree[k].lazy)
	{
		tree[k*2].c=tree[k].c;
		tree[k*2].lazy=tree[k].lazy;
		tree[k*2+1].c=tree[k].c;
		tree[k*2+1].lazy=tree[k].lazy;
		tree[k].lazy=0;
	}
	int mid=(tree[k].l+tree[k].r)>>1;
	if(mid>=r)
		Query(k*2,l,r);
	else if(mid<l)
		Query(k*2+1,l,r);
	else
	{
		Query(k*2,l,mid);
		Query(k*2+1,mid+1,r);
	}
}

void Count(int x)
{
	int sum=0;
	while(x)
	{
		x-=(x&(-x));
		sum++;
	}
	printf("%d\n",sum);
}

void Insert(int k,int l,int r,int c)
{
	if(tree[k].l>=l&&tree[k].r<=r)
	{
		tree[k].c=c;
		tree[k].lazy=1;
		return;
	}
	if(tree[k].lazy)
	{
		tree[k*2].c=tree[k].c;
		tree[k*2].lazy=tree[k].lazy;
		tree[k*2+1].c=tree[k].c;
		tree[k*2+1].lazy=tree[k].lazy;
		tree[k].lazy=0;
	}
	int mid=(tree[k].l+tree[k].r)>>1;
	if(mid>=r)
		Insert(k*2,l,r,c);
	else if(l>mid)
		Insert(k*2+1,l,r,c);
	else
	{
		Insert(k*2,l,mid,c);
		Insert(k*2+1,mid+1,r,c);
	}
	tree[k].c=tree[k*2].c|tree[k*2+1].c;
}

int main()
{
	int n,t,m;
	while(scanf("%d%d%d",&n,&t,&m)!=EOF&&(n!=0&&t!=0&&m!=0))
	{
		int i,a,b,w;
		char c;
		BuildTree(1,1,n);
		for(i=1;i<=m;i++)
		{
			getchar();
			scanf("%c",&c);
			if(c=='C')
			{
				scanf("%d%d%d",&a,&b,&w);
				if(a>b)
					swap(a,b);
				Insert(1,a,b,1<<(w-1));
			}
			else
			{
				scanf("%d%d",&a,&b);
				if(a>b)
					swap(a,b);
				ans=0;
				Query(1,a,b);
				Count(ans);
			}
		}
	}
	return 0;
}

