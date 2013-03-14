#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define inf 0x3f3f3f3f

using namespace std;
struct node
{
    int v,nxt,l;
}edge[1000005];
int head[105];
struct P
{
    int g,r;
}light[105];
int dp[105];
bool vis[105];
int e,n,m;
int S,E,ans;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].nxt=head[u];
    edge[e].l=w;
    head[u]=e++;
}

int Cal(int i,int t)
{
    int y=t%light[i].r;
    if(y>=light[i].g)
        return t+light[i].r-y+5;
    else
        return t;
}

void Bfs(int u)
{
    memset(vis,0,sizeof(vis));
    memset(dp,inf,sizeof(dp));
    vis[u]=1;
    dp[u]=5;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            int now=edge[i].l+dp[u];
            int mod=dp[u]%light[u].r;
            if(mod>=light[u].g)
            {
                now+=light[u].r-mod+5;
            }
            if(v==E)
                ans=min(ans,now);
            if(dp[v]==inf||Cal(v,now)<Cal(v,dp[v]))
            {
                dp[v]=now;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        vis[u]=0;
    }
}

int main()
{
    while(scanf("%d%d%d%d",&n,&m,&S,&E)&&(n+m+S+E))
    {
        Init();
        int x,y,w;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&light[i].g,&y,&light[i].r);
            light[i].g+=y;
            light[i].r+=light[i].g;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            AddEdge(x,y,w);
            AddEdge(y,x,w);
        }
        ans=inf;
        Bfs(S);
        //puts("???");
        int mm=ans/60;
        int ss=ans%60;
        printf("%d:%02d\n",mm,ss);
    }
    return 0;
}
