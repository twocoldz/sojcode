#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
struct node
{
    int v,nxt,w;
}edge[200005];
int head[50005];
int n,e;
int dis[50005];
bool vis[50005];

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
}

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].w=w;
    edge[e].nxt=head[u];
    head[u]=e++;
}

void Spfa(int ma)
{
    for(int i=0;i<=ma;i++)
    {
        dis[i]=-1;
    }
    queue<int> q;
    q.push(0);
    vis[0]=1;
    dis[0]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(dis[u]+edge[i].w>dis[v])
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
    while(scanf("%d",&n)==1)
    {
        Init();
        int a,b,c;
        int ma=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a>b)
                swap(a,b);
            ma=max(ma,b+1);
            AddEdge(a,b+1,c);
        }
        for(int i=0;i<ma;i++)
        {
            AddEdge(i,i+1,0);
            AddEdge(i+1,i,-1);
        }
        Spfa(ma);
        printf("%d\n",dis[ma]);
    }
    return 0;
}
