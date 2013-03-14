#include <cstdio>
#include <cstring>
#include <algorithm>

/*long long a[1000005];

void Init()
{
    for(int i=1;i<=100;i++)
    {
        long long sum=i;
        int ii=i;
        while(ii>=5)
        {
            sum+=ii/5;
            ii=ii%5+ii/5;
        }
        a[i]=sum;
        printf("a[%d]=%lld\n",i,sum);
    }

}*/

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        long long l=n*4/5,r=n,ans=n;
        while(l<=r)
        {
            long long mid=(l+r)>>1;
            long long sum=mid;
            long long tt=mid;
            //printf("%lld\n",mid);
            while(tt>=5)
            {
                sum+=tt/5;
                tt=tt/5+tt%5;
            }
            if(sum>=n)
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
