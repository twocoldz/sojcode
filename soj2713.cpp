#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;
const int maxn=100005;
int a[maxn];
int q[maxn];
long long dp[maxn];
int n;
long long m;

void Slove()
{
    int h,r;
    int left=1;
    long long sum=0;
    h=0,r=-1;
    multiset<long long> v;

    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        while(sum>m)
            sum-=a[left++];
        while(h<=r&&a[q[r]]<=a[i])
        {
            if(h<r)
            {
                v.erase(dp[q[r-1]]+a[q[r]]);
            }
            r--;
        }

        q[++r]=i;

        if(h<r)
            v.insert(dp[q[r-1]]+a[q[r]]);

        while(q[h]<left)
        {
            if(h<r)
                v.erase(dp[q[h]]+a[q[h+1]]);
            h++;
        }

        dp[i]=dp[left-1]+a[q[h]];
        if(h<r&&dp[i]>*(v.begin()))
            dp[i]=*(v.begin());
        //cout<<i<<" "<<dp[i]<<" "<<dp[left-1]+a[q[h]]<<" "<<*(v.begin())<<endl;
    }
}



int main()
{
    while(scanf("%d%lld",&n,&m)!=EOF&&n)
    {
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            if(a[i]>m)
            {
                flag=1;
            }
        }
        if(flag)
        {
            printf("-1\n");
            continue;
        }
        a[0]=dp[0]=0;
        Slove();
        printf("%lld\n",dp[n]);
    }
    return 0;
}
