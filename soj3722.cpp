#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int a[1005][1005];
int dp[1005][1005];

int max3(int a,int b,int c)
{
    return max(max(a,b),c);
}

int main()
{
    int cases;
    scanf("%d",&cases);
    for(int id=1;id<=cases;id++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",a[i]+j);
        dp[n-1][m-1]=a[n-1][m-1];
        for(int i=m-2;i>=0;i--)
            dp[n-1][i]=dp[n-1][i+1]+a[n-1][i];
        for(int i=n-2;i>=0;i--)
            dp[i][m-1]=dp[i+1][m-1]+a[i][m-1];
        n--,m--;
        while(true)
        {
            if(n-1>=0)
            {
                for(int i=m-1;i>=0;i--)
                    dp[n-1][i]=max3(dp[n][i],dp[n-1][i+1],dp[n][i+1])+a[n-1][i];
            }

            if(m-1>=0)
            {
                for(int i=n-1;i>=0;i--)
                    dp[i][m-1]=max3(dp[i+1][m-1],dp[i][m],dp[i+1][m])+a[i][m-1];
            }
            n--,m--;
            if(n==0||m==0)
                break;
        }
        printf("Scenario #%d:\n%d\n\n",id,dp[0][0]);
    }
    return 0;
}
