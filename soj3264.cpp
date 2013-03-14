#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[105][105];
int mi[105][105],sum[105][105];
int f[105][105],g[105][105];
int n,m;

void Init()
{
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j==0)
                sum[i][j]=mi[i][j];
            else
                sum[i][j]=sum[i][j-1]+mi[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j==0)
                f[i][j]=mi[i][j];
            else
            {
                if(mi[i][j]<0)
                    f[i][j]=max(f[i][j-1]+2*mi[i][j],mi[i][j]);
                else
                    f[i][j]=max(f[i][j-1],mi[i][j]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(j==m-1)
                g[i][j]=mi[i][j];
            else
            {
                if(mi[i][j]<0)
                    g[i][j]=max(g[i][j+1]+2*mi[i][j],mi[i][j]);
                else
                    g[i][j]=max(g[i][j+1],mi[i][j]);
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",mi[i]+j);
            }
        }
        Init();

        dp[0][0]=max(mi[0][0],g[0][0]);
        for(int i=1;i<m;i++)
        {
            dp[0][i]=sum[0][i-1]+g[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ans=-1000000;
                for(int k=0;k<m;k++)
                {
                    int t;
                    int l=min(k,j);
                    int r=max(k,j);
                    if(l==r)
                        t=dp[i-1][k]+f[i][l]+g[i][l]-mi[i][j];
                    else
                        t=dp[i-1][k]+f[i][l]+sum[i][r-1]-sum[i][l]+g[i][r];
                    if(t>ans)
                        ans=t;
                }
                dp[i][j]=ans;
            }

        }

        printf("%d\n",dp[n-1][m-1]);
    }
    return 0;
}
