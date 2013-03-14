#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int v,nxt;
}edge[2005];
int head[105];
bool vis[105];
int mk[105];
int n,m,k,e;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
    memset(mk,-1,sizeof(mk));
}

void AddEdge(int u,int v)
{
    edge[e].v=v;
    edge[e].nxt=head[u];
    head[u]=e++;
}

bool Hungary(int u)
{
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            vis[v]=1;
            if(mk[v]==-1||Hungary(mk[v]))
            {
                mk[v]=u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&k)==3&&n)
    {
        int a,b,c;
        Init();
        for(int i=0;i<k;i++)
        {
            scanf("%d%d%d",&c,&a,&b);
            if(a&&b)
                AddEdge(a,b);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(Hungary(i))
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
