#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int a[1005],b[1005];
int dp[1005][1005];

int min3(int a,int b,int c)
{
    return min(a,min(b,c));
}

int main()
{
    int n,m;
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&n,&m);
        if(m>=n)
        {
            for(int i=1;i<=n;i++)
                scanf("%d",a+i);
            for(int i=1;i<=m;i++)
                scanf("%d",b+i);
        }
        else
        {
            for(int i=1;i<=n;i++)
                scanf("%d",b+i);
            for(int i=1;i<=m;i++)
                scanf("%d",a+i);
            swap(n,m);
        }
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        memset(dp,inf,sizeof(dp));
        for(int i=0;i<=m;i++)
            dp[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=m;j++)
            {
                dp[i][j]=dp[i][j-1];
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(a[i]-b[j]));
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
