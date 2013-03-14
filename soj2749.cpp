#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF (1<<25)
using namespace std;

int dp[10005],dp1[125];
int v[105],c[105];

void memset(int m,int a[])
{
    int i;
    for(i=0;i<=m;i++)
		a[i]=INF;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int max=0,sum=0,num=0;
        int i,j,k;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
            if(max<v[i])
                max=v[i];
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&c[i]);
            num+=c[i];
            sum+=c[i]*v[i];
        }
        if(sum<m)
        {
            printf("-1\n");
            continue;
        }
        if(sum==m)
        {
            printf("%d\n",num);
            continue;
        }
        memset(max,dp1);
        memset(m+max,dp);
        dp1[0]=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=max/v[i];j++)
            {
                for(k=max;k>=v[i];k--)
                {
                    if(dp1[k-v[i]]+1<dp1[k])
                        dp1[k]=dp1[k-v[i]]+1;
                }
            }
        }
		
        dp[0]=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=(m+max)/v[i]&&j<=c[i];j++)
            {
                for(k=m+max;k>=v[i];k--)
                {
                    if(dp[k-v[i]]+1<dp[k])
                        dp[k]=dp[k-v[i]]+1;
                }
            }
        }
        int min=INF;
        for(i=m;i<=m+max;i++)
        {
            if(min>dp[i]+dp1[i-m])
                min=dp[i]+dp1[i-m];
        }
		
        if(min!=INF)
            printf("%d\n",min);
        else
            printf("-1\n");
    }
	return 0;
}