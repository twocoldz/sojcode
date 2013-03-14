#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

struct node
{
	long long sum,avg;
	int l,r,mid;
}tree[30005*4];

long long num[30005];

void BuildTree(int k,int l,int r)
{
	int mid=(l+r)>>1;
	tree[k].l=l;
	tree[k].r=r;
	tree[k].avg=-1;
	tree[k].mid=mid;
	if(l==r)
	{
		tree[k].avg=tree[k].sum=num[l];
		return;
	}
	BuildTree(k*2,l,mid);
	BuildTree(k*2+1,mid+1,r);
	tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
}

long long Query(int k,int l,int r)
{
	if(l==tree[k].l&&tree[k].r==r)
	{
		return tree[k].sum;
	}
	int mid=tree[k].mid;
	if(tree[k].avg!=-1)
	{
		tree[k*2].sum=tree[k].avg*(tree[k].mid-tree[k].l+1);
		tree[k*2].avg=tree[k].avg;
		tree[k*2+1].sum=tree[k].avg*(tree[k].r-tree[k].mid);
		tree[k*2+1].avg=tree[k].avg;
		tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
		tree[k].avg=-1;
	}
	if(r<=mid)
		return Query(k*2,l,r);
	else if(l>mid)
		return Query(k*2+1,l,r);
	else
		return Query(k*2,l,mid)+Query(k*2+1,mid+1,r);
}

void Updata(int k,int l,int r,long long x)
{
	if(tree[k].l==l&&tree[k].r==r)
	{
		tree[k].sum=x*(r-l+1);
		tree[k].avg=x;
		return;	
	}
	int mid=tree[k].mid;
	if(tree[k].avg!=-1)
	{
		tree[k*2].sum=tree[k].avg*(tree[k].mid-tree[k].l+1);
		tree[k*2].avg=tree[k].avg;
		tree[k*2+1].sum=tree[k].avg*(tree[k].r-tree[k].mid);
		tree[k*2+1].avg=tree[k].avg;
		tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
		tree[k].avg=-1;
	}
	if(r<=mid)
		Updata(k*2,l,r,x);
	else if(l>mid)
		Updata(k*2+1,l,r,x);
	else
	{
		Updata(k*2,l,mid,x);
		Updata(k*2+1,mid+1,r,x);
	}
	tree[k].sum=tree[2*k].sum+tree[2*k+1].sum;
}

void UpdataAll(int k,int l,int r)
{
	if(l==r)
	{
		num[l]=tree[k].avg;
		return;
	}
	if(tree[k].avg!=-1)
	{
		tree[k*2].sum=tree[k].avg*(tree[k].mid-tree[k].l+1);
		tree[k*2].avg=tree[k].avg;
		tree[k*2+1].sum=tree[k].avg*(tree[k].r-tree[k].mid);
		tree[k*2+1].avg=tree[k].avg;
		tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
		tree[k].avg=-1;
	}
	int mid=tree[k].mid;
	UpdataAll(k*2,l,mid);
	UpdataAll(k*2+1,mid+1,r);
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		int i;
		long long ordsum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			ordsum+=num[i];
		}
		BuildTree(1,1,n);
		int l,r;
		while(m--)
		{
			scanf("%d%d",&l,&r);
			if(r<l)
			{
				int t=l;
				r=l;
				l=t;
			}
			long long sum1=Query(1,l,r);
			long long sum=tree[1].sum;
			if(sum<=ordsum)
			{
				sum1=(long long) ceil(1.0*sum1/(r-l+1));
			}
			else
			{
				sum1=(long long) floor(1.0*sum1/(r-l+1));
			}
			Updata(1,l,r,sum1);
		}
		UpdataAll(1,1,n);
		for(i=1;i<=n;i++)
		{
			printf("%lld ",num[i]);
		}
		printf("\n\n");
	}
	return 0;
}