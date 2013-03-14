#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int sum[1000005];
int q[1000005];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int t;
        sum[0]=0;
        q[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&t);
            sum[i]=sum[i-1]+t;
        }
        int ans=-10001;
        int head=0,rear=1;
        for(int i=1;i<=n;i++)
        {
            while(head!=rear&&i-m>q[head])
                head++;
            if(i!=q[head]&&sum[i]-sum[q[head]]>ans)
                ans=sum[i]-sum[q[head]];
            while(head!=rear&&sum[q[rear-1]]>=sum[i])
                --rear;
            q[rear++]=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
