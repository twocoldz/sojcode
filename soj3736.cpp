/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int  sum[1005],ss[1005];
int dp[1005][1005];
int q[1005];

inline int Sqr(int x){return x*x;}
inline long long Q(int j,int k,int i)
{
    return dp[i-1][k]+Sqr(sum[k])-ss[k]-(dp[i-1][j]+Sqr(sum[j])-ss[j]);
}
inline long long S(int j,int k)
{
    return sum[k]-sum[j];
}
inline int Cal(int j,int k)
{
    return ss[k]-ss[j-1]-sum[j-1]*(sum[k]-sum[j-1]);
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
            break;
        sum[0]=ss[0]=0;
        int a;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            sum[i]=sum[i-1]+a;
            ss[i]=ss[i-1]+sum[i-1]*a;
        }
        m++;
        for(int i=1;i<=n;i++)
            dp[1][i]=ss[i];
        for(int i=2;i<=m;i++)
        {
            int head=0,rear=0;
            for(int j=i;j<=n;j++)
            {
                while(rear-head>=2&&Q(q[rear-2],q[rear-1],i)*S(q[rear-1],j-1)>=Q(q[rear-1],j-1,i)*S(q[rear-2],q[rear-1]))
                    rear--;
                q[rear++]=j-1;
                while(rear-head>=2&&Q(q[head],q[head+1],i)<=S(q[head],q[head+1])*sum[j])
                    head++;
                dp[i][j]=dp[i-1][q[head]]+Cal(q[head]+1,j);
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
*/

//四边形不等式
#include <stdio.h>
#include <string.h>
#define MAX 1100
#define INF (1<<30)

int n,m,sum[MAX],cost[MAX][MAX];
int arr[MAX],dp[MAX][MAX],s[MAX][MAX];

void Init()
{
    int i, j;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            if (j < i)
                cost[i][j] = 0;
            else
                cost[i][j] = cost[i][j - 1] + arr[j] * (sum[j - 1] - sum[i - 1]);
    for (i = 0; i <= n; ++i)
    {
        dp[i][0] = cost[1][i];
        s[i][0] = 0,s[n+1][i] = n;
    }
}
int Solve_DP()
{
    int i,j,k;
    for (j = 1; j <= m; ++j)
        for (i = n; i >= 1; --i)
        {
            dp[i][j] = INF;
            for (k = s[i][j-1] ; k <= s[i+1][j]; ++k)
                if (dp[k][j-1] + cost[k+1][i] < dp[i][j])
                {
                    s[i][j] = k;
                    dp[i][j] = dp[k][j-1] + cost[k+1][i];
                }
        }
    return dp[n][m];
}

int main()
{
    int i;
    while (scanf("%d%d",&n,&m)&&n+m)
    {
        for (i = 1; i <= n; ++i)
            scanf("%d",&arr[i]),sum[i] = arr[i] + sum[i-1];
        Init();
        int ans = Solve_DP();
        printf("%d\n",ans);
    }
    return 0;
}
