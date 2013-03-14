#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int a[50005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        int MAX=0;
        int sum=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            if(a[i]>MAX)
            {
                MAX=a[i];
            }
            sum+=a[i];
        }
        int l=MAX;
        int r=sum;
        int ans;
        while(l<=r)
        {
            int d=1;
            int x=0;
            int mid=(l+r)>>1;
            for(int i=1;i<=n;i++)
            {
                x+=a[i];
                if(x>mid)
                {
                    d++;
                    x=a[i];
                }
            }
            if(d<=m)
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
