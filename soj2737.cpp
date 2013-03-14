#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
struct node
{
    int v,nxt;
}edge[10005];
int head[505];
int mk[505];
bool vis[505];
bool fit[505][505];
int n,e;

void Init()
{
    e=0;
    memset(head,-1,(n+1)*sizeof(head[0]));
}

inline void AddEdge(int u,int v)
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

inline int get()
{
    char str[10];
    scanf("%s",str);
    int x=0;
    for(int i=0;str[i];i++)
    {
        x=x*10+str[i]-48;
    }
    return x;
}

int main()
{
    int m;
    while(scanf("%d%d",&n,&m)==2)
    {
        Init();
        //memset(fit,0,sizeof(fit));
        int a,b,ans=0;
        for(int i=1;i<=m;i++)
        {
            a=get();
            b=get();
            AddEdge(a,b);
        }
        memset(mk,-1,sizeof(mk));
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(Hungary(i))
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
