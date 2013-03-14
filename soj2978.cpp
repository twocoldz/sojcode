#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int a[50005];
int dp[50005];
int q[50005];
int n,m;
bool Judge(int tt)
{
    memset(dp,inf,sizeof(dp));
    dp[n+1]=0;
    q[0]=n+1;
    int head=0,rear=0;
    for(int i=n;i>=0;i--)
    {
        while(head!=rear&&q[head]-i-1>tt)
            head++;
        dp[i]=dp[q[head]]+a[i];
        while(head<=rear&&dp[q[rear]]>=dp[i])
            rear--;
        q[++rear]=i;
    }
    if(dp[0]<=m)
        return true;
    return false;
}

int main()
{

    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        a[0]=0;
        int l=0,r=n+1;
        int ans=n+1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(Judge(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
