#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int v,nxt,w;
}edge[100005],q[40005];
const int N=10005;
int heade[N],headq[N];
int dis[N];
int fa[N];
int ans[20005];
bool vis[N];
int n,m,e,Q;

void Init()
{
    e=0;
    memset(heade,-1,sizeof(heade));
    memset(headq,-1,sizeof(headq));
}

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].w=w;
    edge[e].nxt=heade[u];
    heade[u]=e++;
}

void AddQuery(int u,int v)
{
    q[e].v=v;
    q[e].nxt=headq[u];
    headq[u]=e++;
}

int FindFa(int x)
{
    if(fa[x]!=x)
    {
        fa[x]=FindFa(fa[x]);
    }
    return fa[x];
}

void Dfs(int u,int father)
{
    for(int i=heade[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(v!=father)
        {
            dis[v]=dis[u]+edge[i].w;
            Dfs(v,u);
        }
    }
}

void tarjan(int u,int father)
{
    vis[u]=1;
    for(int i=headq[u];~i;i=q[i].nxt)
    {
        int v=q[i].v;
        //printf("u=%d v=%d i=%d vid[v]=%d\n",u,v,i,int(vis[v]));
        if(vis[v]&&ans[i/2]==-1)
        {

            ans[i/2]=dis[u]+dis[v]-2*dis[FindFa(v)];
        }
    }
    for(int i=heade[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(v!=father)
        {
            tarjan(v,u);
            fa[v]=u;
        }
    }
}

void Cal()
{
    dis[1]=0;
    Dfs(1,0);
    memset(vis,0,sizeof(vis));
    //memset(ans,-1,sizeof(ans));
    for(int i=1;i<=n;i++)
        fa[i]=i;
    tarjan(1,0);
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d %d",&n,&Q);
        int a,b,w;
        char c;
        Init();
        //printf("%d\n",m);
        for(int i=1;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&w);
            AddEdge(a,b,w);
            AddEdge(b,a,w);
        }
        e=0;
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d",&a,&b);
            AddQuery(a,b);
            AddQuery(b,a);
            if(a==b)
                ans[i]=0;
            else
                ans[i]=-1;
        }
        Cal();
        for(int i=0;i<Q;i++)
            printf("%d\n",ans[i]);
        printf("\n");
    }
    return 0;
}
