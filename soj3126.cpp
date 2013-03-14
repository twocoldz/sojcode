#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x7fffffff

using namespace std;
int a[1<<20],b[1<<20];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n)
    {
        int t1,t2;
        int sum=0;
        t1=n>>1;
        t2=n-t1;
        bool flag=0;
        for(int i=0;i<t1;i++)
        {
            scanf("%d",a+(1<<i));
            sum+=a[1<<i];
            if(sum==m)
            {
                flag=1;
            }
        }
        for(int i=0;i<t2;i++)
        {
            scanf("%d",b+(1<<i));
            sum+=b[1<<i];
            if(sum==m)
            {
                flag=1;
            }
        }
        if(flag)
        {
            printf("%d\n",m);
            continue;
        }
        b[0]=a[0]=0;
        int ans=-1;
        for(int i=0;i<(1<<t1);i++)
        {
            int t=i&(-i);
            a[i]=a[t]+a[t^i];
            if(a[i]==m)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            printf("%d\n",m);
            continue;
        }
        for(int i=0;i<(1<<t2);i++)
        {
            int t=i&(-i);
            b[i]=b[t]+b[t^i];
            if(b[i]==m)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            printf("%d\n",m);
            continue;
        }
        sort(a,a+(1<<t1));
        sort(b,b+(1<<t2));
        for(int i=0;i<(1<<t1);i++)
        {
            int t=inf;
            int l=0;
            int h=(1<<t2)-1;
            while(l<=h)
            {
                int mid=(l+h)>>1;
                if(a[i]+b[mid]>=m&&a[i]+b[mid]<t)
                {
                    t=a[i]+b[mid];
                    h=mid-1;
                }
                else
                {
                    l=mid+1;
                }
                if(t!=inf&&(ans==-1||ans>t))
                {
                    ans=t;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
