#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define max(a,b) (a>b?a:b)

const int base=100000;
int dp[200005];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        int left=0,right=0;
        int s,t,i,ans=0;
        memset(dp,0x80,sizeof(dp));
		dp[base]=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&s,&t);
            if(s>0)
            {
                for(int j=right+base;j>=left+base;j--)
                {
                    dp[j+s]=max(dp[j+s],dp[j]+t);
                }
                right+=s;
            }
            else
            {
                for(int j=left+base;j<=right+base;j++)
                {
                    dp[j+s]=max(dp[j+s],dp[j]+t);
                }
                left+=s;
            }
        }
        for(i=base;i<=right+base;i++)
        {
			if(dp[i]>=0)
				ans=max(ans,i-base+dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}