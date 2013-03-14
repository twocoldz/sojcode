#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int a[50005],h[50005];

int BinFind(int x,int n)
{
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(x<h[mid])
            r=mid-1;
        else
            l=mid+1;
        //else
        //    return mid+1;
    }
    return l;
}


int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            h[i]=inf;
        }
        //memset(h,inf,sizeof(h));
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int t=BinFind(a[i],n);
            h[t]=min(h[t],a[i]);
            if(t>ans)
                ans=t;
        }

        printf("%d\n",ans);
    }
    return 0;
}
