#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int q[500005];
long long a[500005];
long long sum[500005];
long long dp[500005];

long long GetG(int j,int k)
{
    return dp[j]-dp[k]+sum[k]-sum[j]+j*a[j+1]-k*a[k+1];
}

long long GetS(int j,int k)
{
    return a[j+1]-a[k+1];
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        sum[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",a+i),sum[i]=sum[i-1]+a[i];
        dp[0]=0,q[0]=0;
        int head=0,rear=1;
        for(int i=1;i<=n;i++)
        {
            while(head+1<rear&&GetG(q[head+1],q[head])<=i*GetS(q[head+1],q[head]))
                head++;
            int j=q[head];
            dp[i]=dp[j]+sum[i]-sum[j]-a[j+1]*(i-j);

            if(i>=2*m-1)
            {
                j=i-m+1;
                while(head+1<rear&&(GetG(j,q[rear-1])*GetS(q[rear-1],q[rear-2])<=GetG(q[rear-1],q[rear-2])*GetS(j,q[rear-1])))
                    rear--;
                q[rear++]=i-m+1;
            }
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}
