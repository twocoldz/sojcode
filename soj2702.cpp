#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int v[50005];
int dp[50005];
int pre[50005]; //pre[i]记录i之前的站点 能直接到达i最前的位置
int q[50005];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        v[0]=v[n-1]=0;
        for(int i=1;i<n-1;i++)
        {
            scanf("%d",v+i);
        }
        memset(pre,0xff,sizeof(pre));
        int x,y;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            if(pre[y]==-1||pre[y]>x)
                pre[y]=x;
        }
        int rear=0;
        dp[0]=0;
        q[rear++]=0;
        for(int i=1;i<n;i++)
        {
            //printf("pre[%d]=%d\n",i,pre[i]);
            if(pre[i]==-1)
                continue;
            int l=0,r=rear-1,mid;
            while(l<=r)
            {
                mid=(l+r)>>1;
                if(q[mid]<pre[i])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            if(l>=rear)
                continue;
            dp[i]=dp[q[l]]+v[i];
            while(rear&&dp[q[rear-1]]<=dp[i])
                rear--;
            q[rear++]=i;
        }
        printf("%d\n",dp[n-1]);
    }
    return 0;
}
