#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int v,nxt;
}edge[1000005];
const int N=10005;
int head[N];
int dfn[N],low[N];
bool vis[N];
int num,cnt,e,n,m;
int ma,root,son;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v)
{
    edge[e].v=v;
    edge[e].nxt=head[u];
    head[u]=e++;
}

void tarjan(int u)
{
    int child=0;
    dfn[u]=low[u]=++num;
    vis[u]=1;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(u==root)
                son++;
            else if(low[v]>=dfn[u])
                child++;
        }
        else if(low[u]>dfn[v])
            low[u]=dfn[v];
    }
    ma=max(ma,child+1);
}

int main()
{
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        if(m==0)
        {
            printf("%d\n",n-1);
            continue;
        }
        Init();
        int a,b;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            AddEdge(a,b);
            AddEdge(b,a);
        }
        ma=0;
        int re=0;
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                son=0;
                root=i;
                tarjan(i);
                re++;
                if(son>1)
                    ma=max(son,ma);
            }
        }
        printf("%d\n",re+ma-1);
    }
    return 0;
}
