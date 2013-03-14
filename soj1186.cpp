#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node{int v,nxt;}edge[50005];
int head[305];
bool vis[305];
int mk[305];
int n,e;

void Init()
{
    e=0;
    memset(head,-1,sizeof(head));
    memset(mk,0,sizeof(mk));
}

void AddEdge(int u,int v)
{
    edge[e].v=v;;
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
            if(mk[v]==0||Hungary(mk[v]))
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
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int p,k,a;
        Init();
        scanf("%d%d",&p,&n);
        for(int i=1;i<=p;i++)
        {
            scanf("%d",&k);
            while(k--)
            {
                scanf("%d",&a);
                AddEdge(i,a);
            }
        }
        int ans=0;
        for(int i=1;i<=p;i++)
        {
            memset(vis,0,sizeof(vis));
            if(Hungary(i))
                ans++;
        }
        if(ans==p)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
