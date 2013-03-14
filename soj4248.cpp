#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
int dp[11][55][101],c[11][111][111],f[11],A[11][11];
const int mod=1000000007;

void Init()
{
    int i,j,s;
    for(i=0;i<=10;i++)
        for(j=0;j<=i;j++)
        {
            if(j==0)
                A[i][j]=1;
            else
                A[i][j]=(int)((long long)A[i][j-1]*(long long)(i-j+1)%mod);
        }
    for(i=0;i<=50;i++)
        for(j=0;j<=i;j++)
        {
            c[0][i][j]=1;
            if(j==0||j==i)
                c[1][i][j]=1;
            else
                c[1][i][j]=(c[1][i-1][j-1]+c[1][i-1][j])%mod;
            for(s=2;s<=10;s++)
                c[s][i][j]=(int)((long long)c[s-1][i][j]*(long long)c[1][i][j]%mod);
        }
}

int Cal(int n, int m, int k)
{
    int i,j,s,p;
    memset(dp,0,sizeof(dp));
    for(i=0;i<=n;i++)
        for(j=0;j<=k;j++)
            dp[i][0][j]=1;
    for(p=0;p<=n;p++)
    {
        for(j=1;j<=k;j++)
            for(i=1;i<=m;i++)
            {
                for(s=0;s<=i;s++)
                {
                    dp[p][i][j]+=(int)((long long)dp[p][s][j-1]*(long long)c[p][i][s]%mod);
                    dp[p][i][j]%=mod;
                }
            }
    }
    memset(f,0,sizeof(f));
    f[0]=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
        {
            int temp=(int)((long long)A[i-1][j-1]*(long long)f[i-j]%mod);
            temp=(int)((long long)temp*(long long)dp[j][m][k]%mod);
            if(j%2==0)
                f[i]-=temp;
            else
                f[i]+=temp;
            f[i]=(f[i]%mod+mod)%mod;
        }
    return f[n];
}

int main()
{
     int n,m,k;
     Init();
     while(scanf("%d%d%d",&n,&m,&k)==3)
     {
        printf("%d\n",Cal(n,m,k));
     }
     return 0;
}
