#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int x[15],y[15],dp[1<<15];
int st[230];
int n,m;

bool cmp(int a,int b)
{
    return a>b;
}

bool Cleck(int c)
{
    //printf("len=%d\n",c);
    int tt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            st[tt]=0;
            int xc=x[i]+c,yc=y[j]+c;
            for(int k=0;k<n;k++)
            {
                if((x[k]>=x[i]&&x[k]<=xc)&&(y[k]>=y[j]&&y[k]<=yc))
                {
                    st[tt]|=(1<<k);
                }
            }
            //printf("st[%d]=%d\n",tt,st[tt]);
            tt++;
        }
    }

    sort(st,st+tt,cmp);

    int top=0;
    for(int i=0;i<tt;i++)
    {
        int j;
        for(j=0;j<top;j++)
        {
            if(st[i]==(st[i]&st[j]))
            {
                break;
            }
        }
        if(j==top)
        {
            st[top++]=st[i];
            //printf("st[%d]=%d\n",top-1,st[top-1]);
        }
    }

    for(int i=1;i<(1<<n);i++)
        dp[i]=m+1;
    dp[0]=0;
    for(int i=0;i<(1<<n);i++)
    {
        if(dp[i]<m)
        {
            for(int j=0;j<top;j++)
            {
                if(dp[i]+1<dp[i|st[j]])
                    dp[i|st[j]]=dp[i]+1;
            }
        }
    }
    return dp[(1<<n)-1]<=m;
}

int main()
{
    int t;
    int cases=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",x+i,y+i);
        }
        int l=0,r=64000;
        int ans=64000;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(Cleck(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        printf("Case #%d: %d\n",cases++,ans);
    }
    return 0;
}
