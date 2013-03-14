#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int tree[100005];
int n,m;

int lowbit(int x)
{
	return x&(-x);
}

void Modify(int x,int v)
{
	while(x<=n)
	{
		tree[x]+=v;
		x+=lowbit(x);
	}
}

int Query(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}

int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		memset(tree,0,sizeof(tree));
		int op,x,y;
		while(m--)
		{
			scanf("%d%d%d",&op,&x,&y);
			if(op)
			{
				Modify(x+1,y);
			}
			else
			{
				printf("%d\n",Query(y+1)-Query(x));
			}
		}
	}
	return 0;
}
