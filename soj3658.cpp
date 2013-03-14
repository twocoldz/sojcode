#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int v,nxt;
}edge[100005*2];
int head[100005];
int sum[1000005];
int c[100005];
int ord[100005];
int n,e;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
    memset(c,0,sizeof(c));
}

inline void AddEdge(int u,int v)
{
    edge[e].v=v;
    edge[e].nxt=head[u];
    head[u]=e++;
}

inline int lowbit(int x)
{
    return x&(-x);
}

int Sum(int x)
{
    int s=0;
    while(x>0)
    {
        s+=c[x];
        x-=lowbit(x);
    }
    return s;
}

void Modify(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=lowbit(x);
    }
}

void Dfs(int u,int fa)
{
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(v!=fa)
        {
            sum[ord[v]]=Sum(ord[v]);
            Modify(ord[v],1);
            Dfs(v,u);
            Modify(ord[v],-1);
        }
    }
}

int main()
{
    while(scanf("%d",&n)==1&&n)
    {
        Init();
        int a,b;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            AddEdge(a,b);
            AddEdge(b,a);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            ord[a]=i;
        }
        Modify(ord[1],1);
        sum[ord[1]]=0;
        Dfs(1,0);
        for(int i=1;i<=n;i++)
            printf("%d\n",sum[i]);
    }
    return 0;
}


/*
void Dfs(int u,int p)
{
    vis[u]=1;
    fa[u]=p;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            Dfs(v,u);
        }
    }
}

int Insert(int u)
{
    int i=u;
    int t=0;
    do
    {
        i=fa[i];
        t+=vis[i]?1:0;
    }while(fa[i]!=i);
    vis[u]=1;
    return t;
}
*/
