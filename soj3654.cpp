#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <deque>

#define inf 200000001

using namespace std;
int dis[50005];
struct node
{
    int v,nxt,l;
}edge[100005*2];
queue<int> q;
int head[50005];
bool vis[50005];
int n,e;

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].l=w;
    edge[e].nxt=head[u];
    head[u]=e++;
}

void Init()
{
    vis[1]=1;
    dis[1]=e=0;
    memset(head,-1,sizeof(head));
    for(int i=2;i<=n;i++)
        dis[i]=inf,vis[i]=0;
}

bool Relax(int u,int v,int w)
{
    if(dis[v]>dis[u]+w)
    {
        dis[v]=dis[u]+w;
        return true;
    }
    return false;
}

void Spfa(int rt)
{
    q.push(rt);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(Relax(u,v,edge[i].l)&&!vis[v])
            {
                q.push(v);
                vis[v]=1;
            }
        }
    }
}

int main()
{
    int m,Q;
    while(scanf("%d%d%d",&n,&m,&Q)==3)
    {
        int a,b,w;
        Init();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            AddEdge(a,b,w);
            AddEdge(b,a,w);
        }
        Spfa(1);
        for(int i=1;i<=Q;i++)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",dis[a]+dis[b]);
        }
    }
    return 0;
}






/*int main()
{
    int n,m,Q;
    while(scanf("%d%d%d",&n,&m,&Q)==3)
    {
        dis[1][1]=0;
        for(int i=2;i<=n;i++)
            dis[1][i]=inf;
        node t;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&t.b,&t.e,&t.l);
            if(t.b==1||t.e==1)
                q.push_front(t);
            else
                q.push_back(t);
        }
        memset(vis,0,sizeof(vis));
        vis[1]=1;
        while(!q.empty())
        {
            t=q.front();
            q.pop_front();
            if(!vis[t.b]&&!vis[t.e])
            {
                q.push_back(t);
                continue;
            }
            else
            {
                dis[1][t.b]=min(dis[1][t.b],dis[1][t.e]+t.l);
                dis[1][t.e]=min(dis[1][t.e],dis[1][t.b]+t.l);
                vis[t.b]=vis[t.e]=1;
            }
        }
        int a,b;
        for(int i=1;i<=Q;i++)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",dis[1][a]+dis[1][b]);
        }
    }
    return 0;
}*/


/*
for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&l);
            dis[1][a]=min(dis[1][b]+l,dis[1][a]);
            dis[1][b]=min(dis[1][a]+l,dis[1][b]);
            printf("dis[1][%d]=%d dis[1][%d]=%d\n",a,dis[1][a],b,dis[1][b]);
            //dis[a][b]=min(dis[a][b],l);
            //dis[b][a]=min(dis[b][a],l);
            for(int j=1;j<=n;j++)
            {
                dis[j][b]=min(dis[j][b],dis[j][a]+dis[a][b]);
                dis[b][j]=dis[j][b];
                dis[j][a]=min(dis[j][a],dis[j][b]+dis[a][b]);
                dis[a][j]=dis[j][a];
            }
        }
*/
