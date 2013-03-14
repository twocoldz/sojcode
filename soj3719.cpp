#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
struct node
{
    int v,w;
    node(int x,int y)
    {
        v=x;
        w=y;
    }
    bool operator <(const node&b) const
    {
        return w>b.w;
    }
};
priority_queue<node> q;
vector<node> e[10005];
int dis[10005];
bool vis[10005];

void GetDis()
{
    while(!q.empty())
    {
        node u=q.top();
        q.pop();
        if(vis[u.v])
            continue;
        vis[u.v]=1;
        dis[u.v]=u.w;
        for(int i=0;i<e[u.v].size();i++)
        {
            int v=e[u.v][i].v;
            int d=e[u.v][i].w;
            if(dis[v]>d+u.w)
            {
                dis[v]=d+u.w;
                q.push(node(v,dis[v]));
            }
        }
    }
}

int main()
{
    int cases;
    scanf("%d",&cases);
    for(int id=1;id<=cases;id++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",dis+i);
            q.push(node(i,dis[i]));
            vis[i]=0;
        }
        for(int i=0;i<=n;i++)
            e[i].clear();
        int a,b,w1,w2;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&a,&b,&w1,&w2);
            e[a].push_back(node(b,w1));
            e[b].push_back(node(a,w2));
        }
        GetDis();
        int ans=0;
        for(int i=1;i<n;i++)
            if(dis[ans]<dis[i])
                ans=i;
        printf("Scenario #%d:\n%d\n\n",id,ans);
    }
    return 0;
}
