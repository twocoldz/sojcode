#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define inf 0x3f3f3f3f

using namespace std;
struct node
{
    int v,nxt,l;
}edge[10005];
int head[105];
int ft[105];
int dis[105];
bool vis[105];
int n,e,S,E;

void Init()
{
    e=0;
    memset(dis,inf,sizeof(dis));
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
}

void AddEdge(int u,int v,int w)
{
    edge[e].v=v;
    edge[e].l=w;
    edge[e].nxt=head[u];
    head[u]=e++;
}

void Spfa()
{
    queue<int> q;
    dis[S]=0;
    vis[S]=1;
    q.push(S);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            //printf("v=%d\n",v);
            //system("PAUSE");
            if((dis[v]>dis[u]+edge[i].l)
               &&(dis[u]+edge[i].l<=ft[u])
               &&(dis[u]+edge[i].l<=ft[v]))
            {
                dis[v]=dis[u]+edge[i].l;
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
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d%d",&n,&S,&E);
        Init();
        int a;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",ft+i);
            if(ft[i]==0)
                ft[i]=inf;
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a);
                if(a)
                {
                    AddEdge(i,j,a);
                }
            }
        }
        Spfa();
        if(dis[E]==inf)
            printf("GENE HACKMAN\n");
        else
            printf("%d\n",dis[E]);
    }
    return 0;
}
