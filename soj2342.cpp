#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int a,b,s;
    bool operator < (const node &c) const
    {
        return s<c.s;
    }
}g[205];
bool fit[205][205];
int mk[205];
bool vis[205];
int n;
bool Hungary(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(fit[u][i]&&!vis[i])
        {
            vis[i]=1;
            if(mk[i]==-1||Hungary(mk[i]))
            {
                mk[i]=u;
                return true;
            }
        }
    }
    return false;
}

void swap(int &a,int &b)
{
    a^=b;
    b^=a;
    a^=b;
}

int main()
{
    while(scanf("%d",&n)&&n)
    {
                int ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&g[i].a,&g[i].b);
            if(g[i].a>g[i].b)
                swap(g[i].a,g[i].b);
            g[i].s=g[i].a*g[i].b;
            ans+=g[i].s;
        }
        sort(g+1,g+n+1);
        //for(int i=1;i<=n;i++)
        //    printf("%d %d %d\n",g[i].a,g[i].b,g[i].s);
        memset(fit,0,sizeof(fit));
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(g[i].a<=g[j].a&&g[i].b<=g[j].b)
                    fit[i][j]=1;
            }
        }
        memset(mk,-1,sizeof(mk));
        for(int i=n;i>=1;i--)
        {
            memset(vis,0,sizeof(vis));
            Hungary(i);
        }
        for(int i=1;i<=n;i++)
            if(mk[i]!=-1)
                ans-=g[mk[i]].s;
        printf("%d\n",ans);
    }
    return 0;
}
