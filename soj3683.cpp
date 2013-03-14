#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
struct node
{
    int nxt;
    long long l;
};
vector<node> son[50005];
long long dp[50005][12];
bool vis[50005][12];

long long max(long long a,long long b)
{
    return a>b?a:b;
}
long long min(long long a,long long b)
{
    return a<b?a:b;
}

long long Dfs(int u,int k)
{
    if(!vis[u][k])
    {
        dp[u][k]=0;
        vis[u][k]=1;
        for(int i=0;i<son[u].size();i++)
        {
            dp[u][k]=max(dp[u][k],Dfs(son[u][i].nxt,k)+son[u][i].l);
        }
        if(k>0)
        {
            for(int i=0;i<son[u].size();i++)
            {
                dp[u][k]=min(dp[u][k],Dfs(son[u][i].nxt,k-1)+son[u][i].l);
            }
        }
    }
    return dp[u][k];
}

int main()
{
    int n,v,m;
    while(scanf("%d%d%d",&n,&v,&m)==3)
    {
        int a;
        node t;
        for(int i=1;i<=n;i++)
            son[i].clear();
        for(int i=1;i<=v;i++)
        {
            scanf("%d%d%lld",&a,&t.nxt,&t.l);
            son[a].push_back(t);
        }
        memset(vis,0,sizeof(vis));
        long long  ans=Dfs(1,m);
        printf("%lld\n",ans);
    }
    return 0;
}
