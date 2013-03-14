#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 2000000000
using namespace std;

#define min(a,b) (a<b?a:b)

int dp[50005],dp1[50005];
int p[105],c[105];

int main()
{
    int n,h;
	int max=0;
    while(scanf("%d%d",&n,&h)==2&&n)
    {
        int i,j;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&p[i],&c[i]);
			if(p[i]>max)
				max=p[i];
        }
        for(i=1;i<=h+max;i++)
		{
			dp[i]=INF;
		}
        dp[0]=0;
        for(i=1;i<=n;i++)
        {
            for(j=p[i];j<=h+max;j++)
            {
                dp[j]=min(dp[j],dp[j-p[i]]+c[i]);
            }
        }
		int min=dp[h];
		for(i=h;i<=h+max;i++)
		{
			if(dp[i]<min)
				min=dp[i];
		}
		printf("%d\n",min);
    }
    return 0;
}