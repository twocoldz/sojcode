#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int v,nxt;
}edge[1005*1005];
int head[1005],sg[1005];
int n,e;

void Init()
{
    e=0;
    memset(sg,-1,sizeof(sg));
    memset(head,-1,sizeof(head));
}

void AddEdge(int u,int v)
{
    edge[e].v=v;
    edge[e].nxt=head[u];
    head[u]=e++;
}

int Dfs(int u)
{
    if(sg[u]!=-1)
        return sg[u];
    bool vis[1005]={0};
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].v;
        vis[Dfs(v)]=1;
    }
    int k=0;
    while(vis[k++]);
    sg[u]=k-1;
    return sg[u];
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        Init();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            while(k--)
            {
                int x;
                scanf("%d",&x);
                AddEdge(i,x);
            }
        }
        int m;
        int ans=0;
        //for(int i=0;i<n;i++)
        //{
        //    printf("%d\n",Dfs(i));
        //}
        scanf("%d",&m);
        while(m--)
        {
            int x;
            scanf("%d",&x);
            ans^=Dfs(x);
        }
        if(ans)
        {
            puts("yy");
        }
        else
            puts("mm");
    }
    return 0;
}
