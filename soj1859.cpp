#include <cstdio>
#include <cstring>

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",((long long)n*(long long)n*(long long )n+5*(long long)n)/6+1);
    }
    return 0;
}
