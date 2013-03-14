#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int a[102];
int dp[102][5][1<<5];   //dp[i][j][k]表示前i个炸弹最后一个颜色为j状态为k时需要拆除的炸弹数

inline int min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
        {
            break;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            a[i]--;
        }

        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<(1<<m);j++)
            {
                dp[0][i][j]=10000;
            }
        }

        for(int i=0;i<m;i++)
        {
            dp[0][i][1<<i]=0;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<(1<<m);k++)
                {
                    dp[i+1][j][k]=dp[i][j][k]+1;
                }
            }

            for(int j=0;j<m;j++)
            {
                for(int k=0;k<(1<<m);k++)
                {
                    if(dp[i][j][k]==10000)
                        continue;
                    if(a[i+1]==j)
                    {
                        dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
                    }
                    else
                    {
                        if(k&(1<<a[i+1]))
                        {
                            continue;
                        }
                        else
                        {
                            int t=k|(1<<a[i+1]);
                            dp[i+1][a[i+1]][t]=min(dp[i+1][a[i+1]][t],dp[i][j][k]);
                        }
                    }
                }
            }
        }

        int ans=10000;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<(1<<m);j++)
            {
                ans=min(ans,dp[n][i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
