#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int v,nxt;
}edge[1000005];
const int N=1005;
int mk[N],mx[N],head[N];
int a[N];
bool vis[N];
int n,e;

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

bool G[10][10] = {
    { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
    { 0, 1, 0, 1, 1, 1, 0, 1, 0, 0 }
};

char str[2005];
int main()
{
    while(scanf("%d",&n)==1)
    {
        Init();
        getchar();
        gets(str);
        for(int i=n,j=0;i>=1;j++,i--)
            a[i]=str[j*2]-48;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==8)
                    continue;
            for(int j=i+1;j<=n;j++)
            {
                if(G[a[j]][a[i]])
                    AddEdge(i,j);
            }
        }
        int ans=0;
        memset(mk,-1,sizeof(mk));
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(!Hungary(i))
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
