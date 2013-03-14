#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define Maxn 1000000000
#define  min(a,b) a<b?a:b

struct node
{
	int num;
	int l,r;
}tree[30005*2];
int n;

int game[30005];



void BulidTree(int left,int right,int u)
{
	tree[u].l=left;
	tree[u].r=right;
	if(left==right)
	{
		tree[u].num=game[left];
		return;
	}
	int mid=(left+right)/2;
	BulidTree(left,mid,u*2);
	BulidTree(mid+1,right,u*2+1);
	tree[u].num=min(tree[2*u].num,tree[2*u+1].num);
}


int Query(int left,int right,int u)
{
	if(tree[u].l==left&&tree[u].r==right)
	{
		return tree[u].num;
	}
	if(right<=tree[2*u].r)
	{
		return Query(left,right,u*2);
	}
	else if(left>=tree[2*u+1].l)
	{
		return Query(left,right,u*2+1);
	}
	else
	{
		return min(Query(left,tree[2*u].r,u*2),Query(tree[2*u+1].l,right,u*2+1));
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	//	memset(tree,1000000001,sizeof(tree));
		int m;
		scanf("%d",&n);
		int i,x,y;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&game[i]);
		}
		BulidTree(1,n,1);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",Query(x,y,1));
		}
	}
	return 0;
}

