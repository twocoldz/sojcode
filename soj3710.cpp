#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long dp[1000005];
long long sum[1000005];
int q[1000005];
int a,b,c;

inline long long Sqr(long long x){return x*x;}
inline long long G(int j,int k)
{
    return dp[j]-b*sum[j]+a*Sqr(sum[j])-(dp[k]-b*sum[k]+a*Sqr(sum[k]));
}
inline long long S(int j,int k)
{
    return 2*a*(sum[j]-sum[k]);
}
inline long long Cal(int i,int j)
{
    return dp[j]+a*Sqr(sum[i]-sum[j])+b*(sum[i]-sum[j])+c;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        scanf("%d%d%d",&a,&b,&c);
        int x;
        sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sum[i]=sum[i-1]+x;
            //printf("%d\n",sum[i]);
        }
        dp[0]=q[0]=0;
        int head=0,rear=1;
        for(int i=1;i<=n;i++)
        {
            while (rear - head >= 2 && G(q[head], q[head + 1]) < sum[i] * S(q[head], q[head + 1]))
                head++;
            dp[i] = Cal(i,q[head]);
            while (rear - head >= 2 && G(q[rear - 2], q[rear - 1]) * S(q[rear - 1], i) >= G(q[rear - 1], i) * S(q[rear - 2], q[rear - 1]))
                rear--;
            q[rear++] = i;
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}
