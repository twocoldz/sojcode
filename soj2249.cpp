#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
	int pos;
	int ord;
}post[20005];

bool cmp1(node a,node b)
{
	return a.pos<b.pos;
};

bool cmp2(node a,node b)
{
	if(a.ord==b.ord)
		return a.pos<b.pos;
	return a.ord>b.ord;
}

struct T
{
	int l,r;
	bool vis;
}tree[20*20005];
int flag;

void BulidTree(int left,int right,int u)
{
	tree[u].l=left;
	tree[u].r=right;
	tree[u].vis=false;
	if(left==right)
		return;
	int mid=(left+right)/2;
	BulidTree(left,mid,u*2);
	BulidTree(mid+1,right,u*2+1);
}

void Query(int left,int right,int u)
{
	if(tree[u].vis)
		return;
	if(tree[u].l==left&&tree[u].r==right)
	{
		tree[u].vis=true;
		flag=true;
		return;
	}
	if(right<=tree[u*2].r)
	{
		Query(left,right,u*2);
	}
	else if(left>=tree[u*2+1].l)
	{

		Query(left,right,u*2+1);
	}
	else
	{
		Query(left,tree[u*2].r,u*2);
		Query(tree[2*u+1].l,right,u*2+1);
	}
	tree[u].vis=tree[u*2].vis&tree[u*2+1].vis;
}

int main()
{
	int n,m,sum;
	scanf("%d",&n);
	while(n--)
	{
		sum=0;
		int i;
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&post[i*2-1].pos,&post[i*2].pos);
			post[i*2-1].ord=post[i*2].ord=i;
		}
		sort(post+1,post+2*m+1,cmp1);
		int index=0,pre=-1;
		for(i=1;i<=2*m;i++)
		{
			if(post[i].pos!=pre)
			{
				pre=post[i].pos;
				post[i].pos=++index;
			}
			else
				post[i].pos=index;
		}
		sort(post+1,post+2*m+1,cmp2);
		BulidTree(1,index,1);
		for(i=1;i<=2*m;i+=2)
		{
			flag=false;
			Query(post[i].pos,post[i+1].pos,1);
			if(flag)
				sum++;			
		}
		printf("%d\n",sum);
	}
	return 0;
}
