#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define max(a,b) a>b?a:b

using namespace std;

struct node
{
	int l,r;
	long long h;
	long long lazy;
}tree[200005*8];

struct rel
{
	int b;
	int e;
	int high;
}reg[100010];

int help[200010];
int len;

//bool cmp1(rel a,rel b)
//{
//	return a.pos<b.pos;
//}
//
//bool cmp2(rel a,rel b)
//{
//	if(a.ord==b.ord)
//		return a.pos<b.pos;
//	return a.ord<b.ord;
//}

void BuildTree(int k,int l,int r)
{
	tree[k].h=0;
	tree[k].l=l;
	tree[k].r=r;
	tree[k].lazy=0;
	if(l==r)
	{
		return;
	}
	int mid=(l+r)>>1;
	BuildTree(k*2,l,mid);
	BuildTree(k*2+1,mid+1,r);
}

long long Query(int k,int l,int r)
{
	tree[k].h=max(tree[k].h,tree[k].lazy);
	if((l==tree[k].l&&tree[k].r==r)||(tree[k].l==tree[k].r))
	{
		return tree[k].h;
	}
	int mid=(tree[k].l+tree[k].r)>>1;
	tree[k*2].lazy=max(tree[k].lazy,tree[k*2].lazy);
	tree[k*2+1].lazy=max(tree[k].lazy,tree[k*2+1].lazy);
	if(r<=mid)
	{
		return Query(k*2,l,r);
	}
	else if(l>mid)
	{
		return Query(k*2+1,l,r);
	}
	else
	{
		return max(Query(k*2,l,mid),Query(k*2+1,mid+1,r));
	}
}

void Insert(int k,int l,int r,long long h)
{
	if((l==tree[k].l&&tree[k].r==r)||(tree[k].l==tree[k].r))
	{
		tree[k].h=h;
		tree[k].lazy=h;
		return;
	}
	int mid=(tree[k].r+tree[k].l)>>1;
	tree[k].h=max(tree[k].h,h);
	if(r<=mid)
	{
		Insert(k*2,l,r,h);
	}
	else if(l>mid)
	{
		Insert(k*2+1,l,r,h);
	}
	else
	{
		Insert(k*2,l,mid,h);
		Insert(k*2+1,mid+1,r,h);
	}
}

int BinF(int x)
{
	int l = 1;
	int r = len;
	while(l <= r)
	{
		int mid = (l+r)>>1;
		if(help[mid] == x)
			return mid;
		else if(help[mid] > x)
			r = mid - 1;
		else
			l = mid + 1;
	}
 }

int main()
{
	int n,w;
	while(scanf("%d%d",&n,&w)!=EOF&&n&&w)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&reg[i].b,&reg[i].e,&reg[i].high);
			help[i]=reg[i].b;
			help[i+n]=reg[i].e;
		}
//		sort(reg+1,reg+2*n+1,cmp1);

//		int index=1;
//		int pre=reg[i].pos;
//		reg[i].pos=1;
//		for(i=2;i<=2*n;i++)
//		{
//			if(reg[i].pos!=pre)
//			{
//				index++;
//				pre=reg[i].pos;
//			}
//			reg[i].pos=index;
//		}
		sort(help+1,help+1+2*n);
		len=unique(help+1,help+1+2*n)-(help+1);
		BuildTree(1,1,len);
//		sort(reg+1,reg+2*n+1,cmp2);
		for(i=1;i<=n;i++)
		{
			int l=BinF(reg[i].b);
			int r=BinF(reg[i].e);
			long long  h=Query(1,l,r);
			Insert(1,l,r,reg[i].high+h);
		}
		printf("%lld\n",Query(1,1,len));
	}
	return 0;
}