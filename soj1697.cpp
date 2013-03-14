#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define inf 0x3f3f3f3f
using namespace std;
struct node
{
    int v,nxt,w;
}edge[200];
int n,e;
int head[30];
bool vis[30];
int dis[30];

void Init()
{
    e=0;
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].w=w;
    edge[e].nxt=head[u];
    head[u]=e++;
}

bool Spfa(int m)
{
    int cnt[25]={0};
    for(int i=1;i<=24;i++)
        dis[i]=-inf;
    dis[0]=0;
    queue<int> q;
    q.push(0);
    cnt[0]=1;
    vis[0]=1;
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
                cnt[v]++;
                if(cnt[v]>24)
                    return 0;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if(dis[24]==m)
        return 1;
    return 0;
}

int r[25];
int x[25];

void BuildGraph(int m)
{
    Init();
    AddEdge(0,24,m);
    for(int i=1;i<=24;i++)
    {
        AddEdge(i-1,i,0);
        AddEdge(i,i-1,-x[i]);
    }
    for(int i=1;i<=8;i++)
        AddEdge(i+16,i,r[i]-m);
    for(int i=9;i<=24;i++)
        AddEdge(i-8,i,r[i]);
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        for(int i=1;i<=24;i++)
            scanf("%d",r+i),x[i]=0;
        scanf("%d",&n);
        int st;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&st);
            x[st+1]++;
        }
        int ans=-1;
        for(int i=0;i<=n;i++)
        {
            BuildGraph(i);
            if(Spfa(i))
            {
                ans=i;
                break;
            }
        }
        if(ans==-1)
            printf("No Solution\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
