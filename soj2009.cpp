#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

long long dp[65][35][102],ans; //dp[i][j][k]  ��ʾ���Ϊi������1�ĸ���Ϊj��mod��m����������Ϊk�������������

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
                    dp[i+1][j][(k<<1)%m]+=dp[i][j][k];       //���油0��j����
                    dp[i+1][j+1][((k<<1)+1)%m]+=dp[i][j][k]; //���油1��j+1
                }
            }
        }
        printf("Case %d: %lld\n",cases,dp[n][n/2][0]);
    }
    return 0;
}
