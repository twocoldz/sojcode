#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int a[1<<20],b[1<<20];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int t1=n/2;
        int t2=n-t1;
        int sum=0;
        bool flag=0;
        for(int i=0;i<t1;i++)
        {
            scanf("%d",&a[1<<i]);
            sum+=a[1<<i];
            if(sum==m)
            {
                flag=1;
            }
        }
        for(int i=0;i<t2;i++)
        {
            scanf("%d",&b[1<<i]);
            sum+=b[1<<i];
            if(sum==m)
            {
                flag=1;
            }
        }
        if(sum<m)
        {
            printf("-1\n");
            continue;
        }
        if(flag)
        {
            printf("%d\n",m);
            continue;
        }
        a[0]=b[0]=0;
        for(int i=0;i<(1<<t1);i++)
        {
            int t=i&(-i);
            a[i]=a[t]+a[t^1];
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
            b[i]=b[t]+b[t^1];
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
        int ans=-1;
        for(int i=0;i<(1<<t1);i++)
        {
            int t=inf;
            int l=0;
            int r=(1<<t2)-1;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(a[i]+b[mid]>=m&&a[i]+b[mid]<t)
                {
                    t=a[i]+b[mid];
                    r=mid-1;
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
