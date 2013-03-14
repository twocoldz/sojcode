#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100005];
int num[100005];

struct node
{
	int l,r;
	int cnt;
}tree[100005*4];

void BuildTree(int left,int right,int u)
{
	tree[u].l=left;
	tree[u].r=right;
	tree[u].cnt=right-left+1;
	if(left==right)
	{
		return;
	}
	int mid=(left+right)/2;
	BuildTree(left,mid,u*2);
	BuildTree(mid+1,right,u*2+1);
}

int Query(int u,int k)
{
	if(tree[u].l==tree[u].r)
	{
		tree[u].cnt--;
		return tree[u].l;
	}
	if(tree[2*u+1].cnt>k)
	{
		int ans=Query(u*2+1,k);
		tree[u].cnt--;
		return ans;
	}
	else
	{
		int ans=Query(u*2,k-tree[2*u+1].cnt);
		tree[u].cnt--;
		return ans;
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		BuildTree(1,n,1);
		memset(num,0,sizeof(num));
		for(i=n;i>=1;i--)
		{
			int k=Query(1,a[i]);
			num[k]=i;
		}
		for(i=1;i<=n;i++)
		{
			i==1?printf("%d",num[i]):printf(" %d",num[i]);
		}
		printf("\n");
	}
	return 0;
}
