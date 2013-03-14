#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int son[155],bro[155];
bool rt[155];
int dp[155][155];
int n,p;

void Dfs(int t)
{
    for(int i=0;i<=p;i++)
    {
        dp[t][i]=inf;
    }
    dp[t][1]=0;
    int k=son[t];
    while(k)
    {
        Dfs(k);
        for(int i=p;i>=0;i--)
        {
            int tt=dp[t][i]+1;
            for(int j=0;j<=i;j++)
            {
                tt=min(tt,dp[k][i-j]+dp[t][j]);
            }
            dp[t][i]=tt;
        }
        k=bro[k];
    }
}

int main()
{

    while(scanf("%d%d",&n,&p)==2)
    {
        memset(son,0,sizeof(son));
        memset(bro,0,sizeof(bro));
        memset(rt,0,sizeof(rt));
        int x,y;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            bro[y]=son[x];
            son[x]=y;
            rt[y]=true;
        }
        int root;
        for(int i=1;i<=n;i++)
        {
            if(!rt[i])
            {
                root=i;
                break;
            }
        }
        Dfs(root);
        int ans=dp[root][p];
        for(int i=1;i<=n;i++)
        {
            if(dp[i][p]<ans)
                ans=dp[i][p]+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
