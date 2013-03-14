#include <iostream>
#include <cstdio>
#include <cstdio>
#include <cstring>

using namespace std;

int son[205],blo[205],w[205];
int dp[205][205];
int n,m;

void Dfs(int v)
{
    dp[v][0]=0,dp[v][1]=w[v];
    int t=son[v];
    while(t!=-1)
    {
        Dfs(t);
        for(int i=m;i>=2;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                dp[v][i]=max(dp[v][i],dp[v][i-j]+dp[t][j]);
            }
        }
        t=blo[t];
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        m++;
        memset(son,-1,sizeof(son));
        memset(blo,-1,sizeof(blo));
        memset(dp,0,sizeof(dp));
        int a,b;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            w[i]=a;
            blo[i]=son[b];
            son[b]=i;
        }

        Dfs(0);
        printf("%d\n",dp[0][m]);
    }
    return 0;
}
