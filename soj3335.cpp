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
int head[1005];
bool vis[1005];
int dis[1005],hdis[1005],cnt[1005];
int n,e;
int S,E;

void Init()
{
    e=0;
    memset(vis,0,(n+1)*sizeof(vis[0]));
    memset(head,-1,(n+1)*sizeof(head[0]));
    memset(dis,inf,(n+1)*sizeof(dis[0]));
    memset(hdis,inf,(n+1)*sizeof(hdis[0]));
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
    //for(int i=1;i<=n;i++)
    //    cnt[i]=0;
    dis[S]=0;
    queue<int> q;
    q.push(S);
    //cnt[S]++;
    vis[S]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(dis[u]+edge[i].w<dis[v])
            {
                dis[v]=dis[u]+edge[i].w;
                //cnt[v]++;
                //if(cnt[v]>n)
                //    return true;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return ;
}

void Half_Spfa()
{
    hdis[S]=0;
    queue<int> q;
    q.push(S);
    vis[S]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(hdis[v]>min(dis[u]+edge[i].w/2,hdis[u]+edge[i].w))
            {
                hdis[v]=min(dis[u]+edge[i].w/2,hdis[u]+edge[i].w);
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return ;
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int m,a,b,w;
        scanf("%d%d%d%d",&n,&m,&S,&E);
        Init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            AddEdge(a,b,w);
        }
        if(S==E)
        {
            printf("0\n");
            continue;
        }
        Spfa();
        if(dis[E]==inf)
        {
            printf("-1\n");
            continue;
        }
        else if(dis[E]==0)
        {
            printf("0\n");
            continue;
        }
        memset(vis,0,(n+1)*sizeof(vis[0]));
        Half_Spfa();
        printf("%d\n",hdis[E]);
    }
    return 0;
}
