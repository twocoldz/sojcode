#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int a[250005],q[250005];
long long sum[250005];
long long dp[250005];

int fun(int x)
{
    if(x>0)
        return 0;
    return x;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            sum[i]=a[i]>0?sum[i-1]+a[i]:sum[i-1];
        }
        int head=0,rear=0;
        q[0]=0;
        dp[0]=0;
        long long ans=-inf;
        for(int i=1;i<=n;i++)
        {
            while(head<rear&&q[head]<i-m)
                head++;
            long long tmp=dp[q[head]];
            ans=max(ans,tmp+sum[i]);
            dp[i]=tmp+fun(a[i])+fun(a[i+1]);
            while(head<rear&&dp[i]>=dp[q[rear]])
                rear--;
            rear++;
            q[rear]=i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
