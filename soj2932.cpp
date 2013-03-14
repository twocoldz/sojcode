#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
struct edge
{
    int v,c,l;
    bool operator < (const edge &a) const
    {
        if(l==a.l)
            return c>a.c;
        else
            return l>a.l;
    }
};
vector<edge> map[105];
int n,K;

int Spfa()
{
    edge u,t;
    u.c=0;
    u.v=1;
    u.l=0;
    priority_queue<edge> q;
    q.push(u);
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        if(u.v==n)
            return u.l;
        for(int i=0;i<map[u.v].size();i++)
        {
            t=map[u.v][i];
            t.c+=u.c;
            if(t.c<=K)
            {
                t.l+=u.l;
                q.push(t);
            }
        }
    }
    return -1;
}

int main()
{
    int m;
    while(scanf("%d%d%d",&K,&n,&m)==3)
    {
        int a,b,c,w;
        edge t;
        for(int i=0;i<=n;i++)
            map[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&a,&b,&w,&c);
            if(c<=K)
            {
                t.v=b;
                t.l=w;
                t.c=c;
                map[a].push_back(t);
            }
        }
        int ans=Spfa();
        printf("%d\n",ans);
    }
    return 0;
}
