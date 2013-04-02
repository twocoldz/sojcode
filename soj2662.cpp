#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;
const int N=505;
struct node
{
    int v,f,nxt;
}edge[100005];
int head[N];
int dis[N],q[N],h,r;
int n,m,e;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v,int w,int rw)
{
    edge[e].v=v;
    edge[e].f=w;
    edge[e].nxt=head[u];
    head[u]=e++;

    edge[e].v=u;
    edge[e].f=rw;
    edge[e].nxt=head[v];
    head[v]=e++;
}

bool Bfs(int s,int t)
{
    memset(dis,0xff,sizeof(dis));
    h=r=0;
    q[++r];
    dis[s]=0;
    while(h<r)
    {
        int u=q[++h];
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(dis[v]==-1&&edge[i].f>0)
            {
                dis[v]=dis[u]+1;
                q[++r]=v;
                if(v==t)
                    return true;
            }
        }
    }
    return false;
}

int Dfs(int s,int t,int limit)
{
    if(s==t)
        return limit;
    int cost=0;
    for(int i=head[s];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(dis[s]+1==dis[v]&&edge[i].f>0)
        {
            int tmp=Dfs(v,t,min(limit-cost,edge[i].f));
            if(tmp>0)
            {
                cost+=tmp;
                edge[i].f-=tmp;
                edge[i^1].f+=tmp;
            }
            if(cost==limit)
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
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        char str[510];
        scanf("%d",&n);
        Init();
        getchar();
        for(int i=1;i<=n;i++)
        {
            gets(str);
            for(int j=0;j<n;j++)
            {
                if(str[j*2]-'0')
                {
                    AddEdge(i,j+1+n,inf,inf);
                }
            }
        }
        int s=0,t=n+n+1;
        for(int i=1;i<=n;i++)
            AddEdge(s,i,1,0),AddEdge(i+n,t,1,0);
        printf("%d\n",Dinic(0,n+n+1));
    }
    return 0;
}
