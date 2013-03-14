#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int n;

int a[50005];
int l[50005],r[50005];
int Cal()
{
    l[0]=0,r[n+1]=0;
    for(int i=1;i<=n;i++)
        l[i]=max(l[i-1],0)+a[i];
    for(int i=1;i<=n;i++)
        l[i]=max(l[i],l[i-1]);//printf("l[%d]=%d\n",i,l[i]);
    for(int i=n;i>=1;i--)
        r[i]=max(r[i+1],0)+a[i];
    for(int i=n;i>=1;i--)
        r[i]=max(r[i],r[i+1]);//printf("l[%d]=%d\n",i,r[i]);
    int ans=-inf;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,l[i]+r[i+1]);
    }
    return ans;
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&n);
        int num=0,sum=0;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i),num+=(a[i]>0),sum+=a[i];
        if(num<=2)
        {
            int ans1=-inf,ans2=-inf;
            for(int i=1;i<=n;i++)
            {
                if(a[i]>ans2)
                {
                    ans2=a[i];
                }
                if(ans1<ans2)
                {
                    swap(ans1,ans2);
                }
            }
            printf("%d\n",ans1+ans2);
            continue;
        }
        int ans=Cal();
        //printf("%d\n",ans);
        for(int i=1;i<=n;i++)
            a[i]=-a[i];
        ans=max(ans,sum+Cal());
        printf("%d\n",ans);
    }
    return 0;
}
/*
#include<cstdio>
#include<algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int maxn=50000+10,inf=~0U>>1;
int t,n,A[maxn],L[maxn],R[maxn];
int Cal()
{
    L[0]=0;
    for(int i=1;i<=n;i++)
        L[i]=max(L[i-1],0)+A[i];
    R[n+1]=0;
    for(int i=n;i>=1;i--)
        R[i]=max(R[i+1],0)+A[i];
    for(int i=1;i<=n;i++)
        L[i]=max(L[i],L[i-1]);
    for(int i=n;i>=1;i--)
        R[i]=max(R[i],R[i+1]);
    int ans=-inf;
    for(int i=1;i<=n;i++)
        ans=max(ans,L[i]+R[i+1]);
    return ans;
}

void Solve()
{
    scanf("%d",&n);
    int z=0,s=0,a=-inf,b=-inf;
    rep(i,n)
        scanf("%d",A+i+1),z+=A[i+1]>0,s+=A[i+1];
    if(z<=2)
    {
        rep(i,n)
        {
            if(A[i+1]>b)
                b=A[i+1];
            if(a<b)
                swap(a,b);
        }
        printf("%d\n",a+b);
        return;
    }
    int ans=Cal();
    rep(i,n)
        A[i+1]=-A[i+1];
    ans=max(ans,s+Cal());
    printf("%d\n",ans);
}
int main()
{ //freopen("in","r",stdin);
     int t;
     scanf("%d",&t);
     rep(i,t)
     Solve();
}
*/
