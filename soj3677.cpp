#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long pow(long long a,long long b,long long p)
{
    long long t=0;
    while(b)
    {
        if(b&1)
            t=(t+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    return t;
}

long long mod(long long a,long long b,long long p)
{
    long long t=1;
    a%=p;
    while(b)
    {
        if(b&1)
            t=pow(t,a,p);
        a=pow(a,a,p);
        b>>=1;
    }
    return t;
}

long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    long long p,e;
    while(scanf("%lld%lld",&p,&e)==2)
    {
        int n;
        long long d;
        if(e>=p-1)
            d=gcd(e,p-1);
        else
            d=gcd(p-1,e);
        d=(p-1)/d;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            long long m;
            scanf("%lld",&m);
            long long t=mod(m,d,p);
            if(t==1)
                printf("TAK\n");
            else
                printf("NIE\n");
        }
    }
    return 0;
}
