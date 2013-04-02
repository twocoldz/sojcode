/*
soj 3134 全局最小割 枚举汇点 300+ms
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
struct node
{
    int v,w,nxt;
}edge[2000010];
const int N=110;
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
int map[N][N];
char str[8000];
int main()
{
    while(scanf("%d",&n)==1)
    {
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
                scanf("%d",map[i]+j);
            gets(str);
        }
        int s=1,t;
        int ans=inf;
        for(t=2;t<=n;t++)
        {
            Init();
            for(int i=1;i<=n;i++)
                for(int j=1;j<i;j++)
                    AddEdge(i,j,map[i][j],map[i][j]);
            ans=min(ans,Dinic(s,t));
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/


#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int N=105;
int map[N][N];
int wet[N];
bool vis[N],combine[N];
int S,T,minCut,n;

void Rearch()
{
    memset(vis,0,sizeof(vis));
    memset(wet,0,sizeof(wet));
    int Max,tmp;
    S=T=-1;
    for(int i=0;i<n;i++)
    {
        Max=-inf;
        for(int j=0;j<n;j++)
            if(!combine[j]&&!vis[j]&&wet[j]>Max)
            {
                tmp=j;
                Max=wet[j];
            }
        if(T==tmp)
            return ;
        S=T;T=tmp;
        minCut=Max;
        vis[tmp]=1;
        for(int j=0;j<n;j++)
            if(!combine[j]&&!vis[j])
                wet[j]+=map[tmp][j];
    }
}

int Stoer_Wagner()
{
    memset(combine,0,sizeof(combine));
    int ans=inf;
    for(int i=0;i<n-1;i++)
    {
        Rearch();
        if(minCut<ans)
            ans=minCut;
        if(ans==0)
            return 0;
        combine[T]=1;
        for(int j=0;j<n;j++)
            if(!combine[j])
            {
                map[S][j]+=map[T][j];
                map[j][S]+=map[j][T];
            }
    }
    return ans;
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",map[i]+j);
        printf("%d\n",Stoer_Wagner());
    }
    return 0;
}
