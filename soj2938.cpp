#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=100005;
struct node
{
	int v;
	node*next;
}edgehead[maxn];

bool vis[maxn];
int n,m,u,v,dep,s;
int low[maxn],high[maxn];
bool apple[maxn];
int tree[maxn*2];

int lowbit(int x)
{
	return x&(-x);
}

void Modify(int x,int k)
{
	while(x<=n)
	{
		tree[x]+=k;
		x+=lowbit(x);
	}
}

int Query(int x)
{
	int sum=0;
	while(x>0)
	{
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}

void dfs(int k)
{
	low[k]=++dep;
	vis[k]=1;

	node*p=edgehead[k].next;
	while(p)
	{
		if(!vis[p->v])
			dfs(p->v);
		p=p->next;
	}
	high[k]=dep;
}

int main()
{
	while(scanf("%d",&n)==1&&n)
	{
		int i;
		memset(edgehead,0,sizeof(edgehead));
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);

			node*p=new node;
			p->v=v;
			p->next=edgehead[u].next;
			edgehead[u].next=p;

			node*q=new node;
			q->v=u;
			q->next=edgehead[v].next;
			edgehead[v].next=q;
		}
		dep=0;
		dfs(1);
		memset(tree,0,sizeof(tree));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++)
		{
			apple[i]=1;
			Modify(i,1);
		}

		scanf("%d",&m);
		getchar();
		char cmd;
		for(i=1;i<=m;i++)
		{
			scanf("%c %d",&cmd,&s);
			getchar();
			if(cmd=='C')
			{
				int k;
				apple[s]=!apple[s];
				k=apple[s]==1?1:-1;
				Modify(low[s],k);
			}
			else if(cmd=='Q')
			{
				printf("%d\n",Query(high[s])-Query(low[s]-1));
			}
		}
	}
	return 0;
}