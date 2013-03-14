#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[500005];
int q[500005];
int sum[500005];
int n,m;

int Sqr(int x){return x*x;}
int Cal(int i,int j)
{
    return dp[j]+m+Sqr(sum[i]-sum[j]);
}
int Cala(int j,int k)
{
    return dp[j]-dp[k]+Sqr(sum[j])-Sqr(sum[k]);
}
int Calb(int j,int k)
{
    return 2*(sum[j]-sum[k]);
}

int main()
{

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int a;
        sum[0]=dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            sum[i]=sum[i-1]+a;
        }
        int head=0,rear=0;
        q[rear++]=0;
        for(int i=1;i<=n;i++)
        {
            while(head+1<rear&&Cala(q[head+1],q[head])<=sum[i]*Calb(q[head+1],q[head]))
                head++;
            dp[i]=Cal(i,q[head]);
            while(head+1<rear&&Cala(i,q[rear-1])*Calb(q[rear-1],q[rear-2])<=Cala(q[rear-1],q[rear-2])*Calb(i,q[rear-1]))
                rear--;
            q[rear++]=i;
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
