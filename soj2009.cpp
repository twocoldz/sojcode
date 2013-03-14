#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

long long dp[65][35][102],ans; //dp[i][j][k]  表示宽度为i，其中1的个数为j，mod（m），后余数为k的排列情况总数

int main()
{
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        int n,k,i,j,m;
        scanf("%d%d",&n,&m);
        if(n%2||m==0)
        {
            printf("Case %d: 0\n",cases);
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[1][1][1%m]=1;
        for(i=1;i<n;i++)
        {
            for(j=0;j<=(n/2);j++)
            {
                for(k=0;k<m;k++)
                {
                    dp[i+1][j][(k<<1)%m]+=dp[i][j][k];       //后面补0，j不变
                    dp[i+1][j+1][((k<<1)+1)%m]+=dp[i][j][k]; //后面补1，j+1
                }
            }
        }
        printf("Case %d: %lld\n",cases,dp[n][n/2][0]);
    }
    return 0;
}
