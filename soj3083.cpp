
#include <stdio.h>


#define modd 19871118


int l[40];

int Cal(long long a,long long b)
{
    int i,j;
    long long d=1;
    for(i=0;b!=0;i++)
    {
        l[i]=b%2;
        b/=2;
    }
    for(j=i-1;j>=0;j--)
    {
        d=(d*d)%modd;
        if(l[j]==1)
        {
            d=(d*a)%modd;
        }
    }
    return d;
}

int main()
{
    long long n,m,ans;
    while(scanf("%lld%lld",&n,&m)==2)
    {
        ans=((m-1)%modd*(m%modd)*Cal(m-1+(m-2)*(m-2),n-1))%modd;
        printf("%lld\n",ans);
    }
    return 0;
}
