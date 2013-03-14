#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1000005];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,p;
        scanf("%d",&n);
        a[0]=-1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p);
            if(p)
                scanf("%d",a+i);
            else
                a[i]=a[i-1]+1;
        }
        sort(a+1,a+n+1);
        long long tt=1,ans=0;
        for(int i=2;i<=n;i++)
        {
            while(a[i]==a[i-1])
            {
                tt++;
                i++;
            }
            ans+=(tt-1)*tt/2;
            tt=1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
