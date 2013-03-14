#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long Cal(long long sum,int n,int m)
{
    long long d=1;
    for(sum%=m;n>0;n>>=1)
    {
        if(n&1)
            d=(d*sum)%m;
        sum=(sum*sum)%m;
    }
    return d;
}

int main()
{
    int t;
    scanf("%d",&t);
    int n,m;
    char c[1005];
    while(t--)
    {
        scanf("%s %d%d",c,&n,&m);
        int sum=0;
        for(int i=0;c[i];i++)
        {
            sum=sum*10+c[i]-'0';
            sum%=m;
        }
        printf("%lld\n",Cal(sum,n,m));
    }
    return 0;
}
