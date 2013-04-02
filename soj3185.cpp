#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
struct node
{
    int v,w,nxt;
}edge[500010];
const int N=410;
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

int lx[N],ly[N],rx[N],ry[N];
int sq[N];

inline bool Judge(int i,int j)
{
    if(rx[i]<=lx[j]||lx[i]>=rx[j]||ry[i]<=ly[j]||ly[i]>=ry[j])
        return false;
    return true;
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&n,&m);
        Init();
        int sum=0;
        for(int i=1;i<=m+n;i++)
            scanf("%d%d%d%d",lx+i,ly+i,rx+i,ry+i),sq[i]=(rx[i]-lx[i])*(ry[i]-ly[i]),sum+=sq[i];
        if(n==0||m==0)
        {
            printf("%d\n",sum);
            continue;
        }
        int s=0,t=n+m+1;
        for(int i=1;i<=n;i++)
        {
            AddEdge(s,i,sq[i],0);
            for(int j=n+1;j<=m+n;j++)
            {
                if(Judge(i,j))
                {
                    AddEdge(i,j,inf,0);
                }
            }
        }
        for(int i=n+1;i<=n+m;i++)
            AddEdge(i,t,sq[i],0);
        printf("%d\n",sum-Dinic(s,t));
    }
    return 0;
}
