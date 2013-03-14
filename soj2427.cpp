#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define inf 0x3f3f3f3f
using namespace std;
struct node
{
    int v,nxt,w;
}edge[20005];
int n,e;
int head[105],dis[105];
bool vis[105];
int S,E;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].w=w;
    edge[e].nxt=head[u];
    head[u]=e++;
}

void Spfa()
{
    memset(dis,inf,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int> q;
    q.push(S);
    dis[S]=0;
    vis[S]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            //printf("u=%d v=%d\n",u,v);
            if(dis[u]+edge[i].w<dis[v])
            {
                dis[v]=dis[u]+edge[i].w;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    int m;
    while(scanf("%d%d",&n,&m)&&n)
    {
        int a,b,w;
        Init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            AddEdge(a,b,w);
            AddEdge(b,a,w);
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&S,&E);
            Spfa();
            if(dis[E]==inf)
                printf("pity\n");
            else
                printf("%d\n",dis[E]);
        }
        printf("\n");
    }
    return 0;
}
