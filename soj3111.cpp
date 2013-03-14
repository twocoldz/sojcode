#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define inf 0x3f3f3f3f

using namespace std;
int x[505],d[505][505],c[505],w[505];
int dp[505][255],f[505][255];
int dw[505][505];
int n,m;

/*inline void Init()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            dp[i][j]=f[i][j]=inf;
    }
    for(int i=1;i<=n;i++)
    {
        d[i][i]=0;
        for(int j=i+1;j<=n;j++)
        {
            d[i][j]=x[j]-x[i];
            d[j][i]=d[i][j];
        }
    }
}*/

int main()
{

    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",x+i,w+i,c+i);
        }

        for(int i=1;i<=n;i++)
        {
            dw[i][i]=0;
            for(int j=i+1;j<=n;j++)
            {
                dw[i][j]=dw[i][j-1]+w[j]*(x[j]-x[i]);
            }
            for(int j=i-1;j>=1;j--)
            {
                dw[i][j]=dw[i][j+1]+w[j]*(x[i]-x[j]);
            }
        }

        memset(dp,inf,sizeof(dp));
        memset(f,inf,sizeof(f));

        dp[0][0]=f[0][0]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i&&j<=m;j++)
            {
                for(int k=i-1;k>=0;k--)
                {
                    if(f[i][j]>dp[k][j-1]+c[i]+dw[i][k+1])
                    {
                        f[i][j]=dp[k][j-1]+c[i]+dw[i][k+1];
                    }
                }
                for(int k=i;k>0;k--)
                {
                    if(dp[i][j]>f[k][j]+dw[k][i])
                    {
                        dp[i][j]=f[k][j]+dw[k][i];
                    }
                }
            }
        }

        int ans=inf;
        for(int i=1;i<=m;i++)
        {
            ans=min(ans,dp[n][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}


//dp[0][0]=0;
/*
        dp[1][1]=c[1];
        pos[1][1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i][1]=c[i];
            pos[i][1]=i;
            for(int j=i-1;j>=1;j--)
            {
                dp[i][1]+=d[i][j]*w[j];
            }
            if(dp[i][1]>dp[i-1][1]+d[pos[i-1][1]][i]*w[i])
            {
                dp[i][1]=dp[i-1][1]+d[pos[i-1][1]][i]*w[i];
                pos[i][1]=pos[i-1][1];
            }
            printf("dp[%d][1]=%d\n",i,dp[i][1]);
            for(int j=2;j<=i&&j<=k;j++)
            {
                if(dp[i-1][j-1]+c[i]<=dp[i-1][j]+d[pos[i-1][j]][i]*w[i])
                {
                    printf("Case1\n");
                    dp[i][j]=dp[i-1][j-1]+c[i];
                    pos[i][j]=i;
                }
                else
                {
                    printf("Case2\n");
                    dp[i][j]=dp[i-1][j]+d[pos[i-1][j]][i]*w[i];
                    pos[i][j]=d[pos[i-1][j]][i];
                }
                printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
            }
        }
        int ans=inf;*/
