#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
struct node
{
    int v,nxt;
}edge[160010];
const int N=404;
int head[N];
int mk[N];
bool vis[N];
struct P
{
    int w,id;
    bool operator <(const P &a) const
    {
        return w>a.w;
    }
}p[N];
int pos[N];
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

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&p[i].w),p[i].id=i;
        sort(p+1,p+n+1);
        for(int i=1;i<=n;i++)
        {
            //printf("w=%d id=%d\n",p[i].w,p[i].id);
            pos[p[i].id]=i;
        }
        Init();
        for(int i=1;i<=n;i++)
        {
            int k,x;
            scanf("%d",&k);
            while(k--)
            {
                scanf("%d",&x);
                AddEdge(pos[i],x);
            }
        }
        memset(mk,-1,sizeof(mk));
        double ans=0.0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(Hungary(i))
            {
                ans+=p[i].w*p[i].w;
            }
        }
        printf("%.06lf\n",sqrt(ans));
    }
    return 0;
}
