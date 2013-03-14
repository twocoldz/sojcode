#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int t=n/m;
        int k=n%m;
        long long ans=(long long)(t)*(long long)(m-1)*(long long)(m)/(long long)2+(long long)(1+k)*(long long)(k)/(long long)2;
        printf("%lld\n",ans);
    }
    return 0;
}
