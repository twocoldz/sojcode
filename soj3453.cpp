#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int v,nxt;
}edge[10005];
const int N=105;
int head[N];
int mk[N];
bool vis[N];
int a[N][26];
int n,e,k;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
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

inline bool Judge(int i,int j)
{
    for(int c=0;c<k;c++)
        if(a[i][c]<=a[j][c])
            return false;
    return true;
}

int main()
{
    int cases;
    scanf("%d",&cases);
    for(int id=1;id<=cases;id++)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<k;j++)
                scanf("%d",a[i]+j);
        }
        Init();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j&&Judge(i,j))
                {
                    AddEdge(i,j);
                }
            }
        }
        int ans=0;
        memset(mk,-1,sizeof(mk));
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(Hungary(i))
                ans++;
        }
        printf("Case #%d: %d\n",id,n-ans);
    }
    return 0;
}
