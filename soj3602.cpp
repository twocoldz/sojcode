#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f
using namespace std;

int a[1005];
int b[1005];
int dp[2][1005];
int n;

void Cal()
{
    dp[0][n]=a[n],dp[1][n]=b[n];
    for(int i=n-1;i>=1;i--)
    {
        int ta=a[i],tb=0;
        int j;
        for(j=i+1;j<=n;j++)
        {
            if(ta==tb)
            {
                dp[0][i]=min(dp[0][i],ta+min(dp[0][j],dp[1][j]));
                break;
            }
            else if(ta>tb)
            {
                dp[0][i]=min(dp[0][i],ta+dp[0][j]);
                tb+=b[j];
            }
            else
            {
                dp[0][i]=min(dp[0][i],tb+dp[1][j]);
                ta+=a[j];
            }
        }
        if(j>n)
            dp[0][i]=min(dp[0][i],max(ta,tb));
        ta=0,tb=b[i];
        for(j=i+1;j<=n;j++)
        {
            if(ta==tb)
            {
                dp[1][i]=min(dp[1][i],ta+min(dp[0][j],dp[1][j]));
                break;
            }
            else if(tb>ta)
            {
                dp[1][i]=min(dp[1][i],tb+dp[1][j]);
                ta+=a[j];
            }
            else
            {
                dp[1][i]=min(dp[1][i],ta+dp[0][j]);
                tb+=b[j];
            }
        }
        if(j>n)
            dp[1][i]=min(dp[1][i],max(ta,tb));
    }
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        memset(dp,inf,sizeof(dp));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",a+i,b+i);
        int T;
        scanf("%d",&T);
        Cal();
        if(min(dp[0][1],dp[1][1])<=T)
        {
            printf("good luck\n");
        }
        else
            printf("impossible\n");
    }
    return 0;
}
