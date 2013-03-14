#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn=5005;

int h[maxn];
int dp[maxn];

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",h+i);
        }
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=0x3f3f3f3f;
            int high=0;
            for(int j=1;j<=min(i,k);j++)
            {
                if((long long)(h[i-j]-h[i])*high>=(long long)(h[i-high]-h[i])*j)
                {
                    high=j;
                    dp[i]=min(dp[i],dp[i-j]+1);
                }
            }
        }
        printf("%d\n",dp[n-1]);
    }
    return 0;
}
