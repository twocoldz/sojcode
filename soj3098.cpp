#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
    int w,v,nxt;
}edge[100005];
const int N=50005;
int head[N];
int fa[N],dep[N];
bool vis[N];
int dis[N][17],st[N][17];
int n,m,e;

struct GE
{
    int u,v,w;
    bool operator <(const GE &a)const
    {
        return w<a.w;
    }
}g[100005];

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
    memset(st,-1,sizeof(st));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        fa[i]=i;
}

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].w=w;
    edge[e].nxt=head[u];
    head[u]=e++;
}

int FindFa(int x)
{
    if(fa[x]!=x)
    {
        fa[x]=FindFa(fa[x]);
    }
    return fa[x];
}

void Dfs(int u,int D)
{
    vis[u]=1;
    dep[u]=D;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            st[v][0]=u;
            dis[v][0]=edge[i].w;
            dep[v]=D+1;
            for(int k=1;(1<<k)<=dep[v];k++)
            {
                st[v][k]=st[st[v][k-1]][k-1];
                dis[v][k]=max(dis[v][k-1],dis[st[v][k-1]][k-1]);
            }
            Dfs(v,D+1);
        }
    }
}

void kruskal()
{
    sort(g,g+m);
    int t=1;
    for(int i=0;t<n&&i<m;i++)
    {
        int fx=FindFa(g[i].u);
        int fy=FindFa(g[i].v);
        if(fx!=fy)
        {
            AddEdge(g[i].u,g[i].v,g[i].w);
            AddEdge(g[i].v,g[i].u,g[i].w);
            fa[fy]=fx;
            t++;
        }
    }
    Dfs(0,0);
}

int Query(int x,int y)
{
    int ans=0;
    if(dep[x]<dep[y])
        swap(x,y);
    int k=(int)(log((double)n)/log(2.0));
    if(1<<(k+1)<=dep[x])
        k++;
    for(int i=k;i>=0;i--)
        if(dep[x]-(1<<i)>=dep[y])
        {
            ans=max(ans,dis[x][i]);
            x=st[x][i];
        }
    if(x==y)
        return ans;
    for(int i=k;i>=0;i--)
    {
        if(st[x][i]!=-1&&st[x][i]!=st[y][i])
        {
            ans=max(ans,dis[x][i]);
            ans=max(ans,dis[y][i]);
            x=st[x][i];
            y=st[y][i];
        }
    }
    ans=max(ans,dis[x][0]);
    ans=max(ans,dis[y][0]);
    return ans;
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        int a,b,w;
        Init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
            g[i].u--,g[i].v--;
        }
        kruskal();
        /*int k=(int)((log((double)n))/log(2.0));
        for(int j=1;j<=k;j++)
            for(int i=0;i<n;i++)
                if(st[i][j-1]!=-1)
                {
                    dis[i][j]=max(dis[i][j-1],dis[st[i][j-1]][j-1]);
                    st[i][j]=st[st[i][j-1]][j-1];
                }
        */
        int Q;
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%d%d",&a,&b);
            a--,b--;
            printf("%d\n",Query(a,b));
        }
        printf("\n");
    }
    return 0;
}
