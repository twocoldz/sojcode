#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int d[50005];
int p[50005];

bool Cleck(int n,int k,int m)
{
    int cnt=0;
    p[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(d[i]-d[p[i-1]]<k)
        {
            p[i]=p[i-1];
            cnt++;
            if(cnt>m)
                return false;
        }
        else
            p[i]=i;
    }
    if(d[n+1]-d[p[n]]<k)
        cnt++;
    return cnt<=m;
}

int main()
{
    int n,m,L;
    while(scanf("%d%d%d",&L,&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",d+i);
        }
        if(n==m)
        {
            printf("%d\n",L);
            continue;
        }
        d[0]=0;
        d[n+1]=L;
        sort(d,d+n+2);
        int l=0;
        int r=L;
        int ans=L;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(Cleck(n,mid,m))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
