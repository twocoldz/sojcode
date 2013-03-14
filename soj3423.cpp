#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define inf 0x3f3f3f3f
using namespace std;
struct node
{
    int v,nxt,w;
}edge[100005];
int head[10005];
int n,e,K;
int dis[10005][23];
bool vis[10005];

struct P
{
    int fa;
    int len;
    bool operator <(const P &a) const
    {
        return len>a.len;
    }
};

void Init()
{
    e=0;
    memset(head,-1,(n+1)*sizeof(head[0]));
    memset(vis,0,(n+1)*sizeof(vis[0]));
}

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].w=w;
    edge[e].nxt=head[u];
    head[u]=e++;
}

/*void Spfa()
{
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(dis[u][0]+edge[i].w<dis[v][0])
            {
                dis[v][0]=dis[u][0]+edge[i].w;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
            for(int j=1;j<=K;j++)
            {
                if(min(dis[u][j]+edge[i].w,dis[u][j-1])<dis[v][j])
                {
                    dis[v][j]=min(dis[u][j]+edge[i].w,dis[u][j-1]);
                    if(!vis[v])
                    {
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
}*/

void Dijkstra(int k)
{
    memset(vis,0,(n+1)*sizeof(vis[0]));
    priority_queue<P> q;
    P u,to;
    u.fa=1;
    u.len=0;
    dis[1][k]=0;
    q.push(u);
    if(k==0)
    {
        while(!q.empty())
        {
            u=q.top();
            q.pop();
            //printf("u=%d\n",u.fa);
            if(vis[u.fa])
                continue;
            for(int i=head[u.fa];~i;i=edge[i].nxt)
            {
                int v=edge[i].v;
                //printf("v=%d\n",v);
                if(vis[v]==0&&dis[v][0]>dis[u.fa][0]+edge[i].w)
                {
                    dis[v][0]=dis[u.fa][0]+edge[i].w;
                    to.fa=v;
                    to.len=dis[v][0];
                    q.push(to);
                }
            }
            vis[u.fa]=1;
        }
    }
    else
    {
        while(!q.empty())
        {
            u=q.top();
            q.pop();
            if(vis[u.fa])
                continue;
            for(int i=head[u.fa];~i;i=edge[i].nxt)
            {
                int v=edge[i].v;
                if(vis[v]==0&&dis[v][k]>min(dis[u.fa][k]+edge[i].w,dis[u.fa][k-1]))
                {
                    dis[v][k]=min(dis[u.fa][k]+edge[i].w,dis[u.fa][k-1]);
                    to.fa=v;
                    to.len=dis[v][k];
                    q.push(to);
                }
            }
            vis[u.fa]=1;
        }
    }
}

int main()
{
    int m;
    while(scanf("%d%d%d",&n,&m,&K)==3)
    {
        Init();
        int a,b,w;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            AddEdge(a,b,w);
            AddEdge(b,a,w);
        }
        for(int i=0;i<=K;i++)
            dis[1][i]=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=K;j++)
                dis[i][j]=inf;
        }
        for(int i=0;i<=K;i++)
            Dijkstra(i);
        printf("%d\n",dis[n][K]);
    }
    return 0;
}
