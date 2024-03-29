
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
struct node
{
    int v,w,nxt;
}edge[500010];
const int N=20010;
int head[N];
int dis[N];
int q[N],h,r;
int n,m,e;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v,int w,int rw)
{
    edge[e].v=v;
    edge[e].w=w;
    edge[e].nxt=head[u];
    head[u]=e++;
    edge[e].v=u;
    edge[e].w=rw;
    edge[e].nxt=head[v];
    head[v]=e++;
}

bool Bfs(int s,int t)
{
    h=r=0;
    memset(dis,0xff,sizeof(dis));
    dis[s]=0;
    q[r++]=s;
    while(r>h)
    {
        int u=q[h++];
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(edge[i].w&&dis[v]==-1)
            {
                dis[v]=dis[u]+1;
                if(v==t)
                    return true;
                q[r++]=v;
            }
        }
    }
    return false;
}

int Dfs(int s,int t,int flow)
{
    if(s==t)
        return flow;
    int cost=0;
    for(int i=head[s];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(edge[i].w&&dis[v]==dis[s]+1)
        {
            int tmp=Dfs(v,t,min(flow-cost,edge[i].w));
            if(tmp>0)
            {
                edge[i].w-=tmp;
                edge[i^1].w+=tmp;
                cost+=tmp;
            }
            if(flow==cost)
                    break;
        }
    }
    if(cost==0)
        dis[s]=-1;
    return cost;
}

int Dinic(int s,int t)
{
    int ans=0;
    while(Bfs(s,t))
        ans+=Dfs(s,t,inf);
    return ans;
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        Init();
        int a,b,w;
        int s=0,t=n+1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            AddEdge(s,i,a,0);
            AddEdge(i,t,b,0);
        }
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&w);
            AddEdge(a,b,w,w);
        }
        printf("%d\n",Dinic(s,t));
    }
    return 0;
}

