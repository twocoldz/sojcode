/*
#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;
struct node
{
    int u,v,nxt,f;
}edge[500000];
const int N=20010;
int head[N];
int dis[N];
int q[N],h,r;
int n,m,e;

void Init()
{
    e=0;
    memset(head,-1,(n+2)*sizeof(head[0]));
}

void AddEdge(int u,int v,int w,int rw)
{
    edge[e].u=u;
    edge[e].v=v;
    edge[e].f=w;
    edge[e].nxt=head[u];
    head[u]=e++;
    edge[e].u=v;
    edge[e].v=u;
    edge[e].f=rw;
    edge[e].nxt=head[v];
    head[v]=e++;
}

int Dinic(int s,int t)
{
    int ans=0;
    while(true)
    {
        int id,i;
        h=r=0;
        memset(dis,0xff,(t+1)*sizeof(dis[0]));
        q[r++]=s;
        dis[s]=0;
        while(h<r)
        {
            id=q[h++];
            for(i=head[id];~i;i=edge[i].nxt)
            {
                int v=edge[i].v;
                if(dis[v]==-1&&edge[i].f>0)
                {
                    dis[v]=dis[edge[i].u]+1;
                    q[r++]=v;
                    if(v==t)
                    {
                        h=r;
                        break;
                    }
                }
            }
        }
        if(dis[t]==-1)
            break;
        r=0;
        id=s;
        while(true)
        {
            if(id==t)
            {
                int flow=inf,bkn;
                for(i=0;i<r;i++)
                    if(edge[q[i]].f<flow)
                    {
                        flow=edge[q[i]].f;
                        bkn=i;
                    }
                for(i=0;i<r;i++)
                {
                    edge[q[i]].f-=flow;
                    edge[q[i]^1].f+=flow;
                }
                ans+=flow;
                r=bkn;
                id=edge[q[bkn]].u;
            }
            for(i=head[id];~i;i=edge[i].nxt)
            {
                int v=edge[i].v;
                if(dis[edge[i].u]+1==dis[v]&&edge[i].f>0)
                    break;
            }
            if(i!=-1)
            {
                q[r++]=i;
                id=edge[i].v;
            }
            else
            {
                if(r==0)
                    break;
                dis[edge[q[r-1]].v]=-1;
                id=edge[q[--r]].u;
            }
        }
    }
    return ans;
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        int a,b,w;
        Init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            AddEdge(0,i,a,0);
            AddEdge(i,n+1,b,0);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            AddEdge(a,b,w,w);
        }
        printf("%d\n",Dinic(0,n+1));
    }
    return 0;
}
*/

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
                if(flow==cost)
                    break;
            }
            else
                dis[v]=-1;
        }
    }
    return cost;
}

int Dinic(int s,int t)
{
    int ans=0;
    while(Bfs(s,t))
    {
        ans+=Dfs(s,t,inf);
    }
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

