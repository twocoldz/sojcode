#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int a[50005];
int n,d;

bool Check(long long m)
{
    long long h=0;
    int i,j=1;
    for(i=1;i<=d;i++)
    {
        h>>=1;
        while(h<m&&j<=n)
        {
            h+=(long long)a[j];
            j++;
        }
        if(h<m)
            return 0;
    }
    return h>=m;
}

int main()
{
    long long sum;
    while(scanf("%d",&n)==1)
    {
        scanf("%d",&d);
        sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            sum+=(long long)a[i];
        }
        long long l=0,r=sum;
        long long ans=0;
        while(l<=r)
        {
            long long mid=(l+r)>>1;
            if(Check(mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
