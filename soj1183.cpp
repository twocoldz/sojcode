#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int v,nxt;
}edge[100005];
const int N=50005;
int head[N];
int mk[N];
bool vis[N];
int n,e;

void Init()
{
    e=0;
    memset(head,-1,(n+1)*sizeof(head[0]));
    memset(mk,-1,(n+1)*sizeof(mk[0]));
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

int Cal()
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        memset(vis,0,(n+1)*sizeof(vis[0]));
        if(Hungary(i))
            ans++;
    }
    return n-ans/2;
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        int a,k,b;
        Init();
        for(int i=0;i<n;i++)
        {
            scanf("%d: (%d)",&a,&k);
            while(k--)
            {
                scanf("%d",&b);
                AddEdge(a,b);
            }
        }
        printf("%d\n",Cal());
    }
    return 0;
}
