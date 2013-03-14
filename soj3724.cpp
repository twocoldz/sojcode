#include <cstdio>
#include <algorithm>

using namespace std;
long long a,b,c;

long long max3(long long a,long long b,long long c)
{
    return max(a,max(b,c));
}
int main()
{
    int cases;
    scanf("%d",&cases);
    for(int id=1;id<=cases;id++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        long long x=max3(a,b,c);
        if(x==a)
            swap(a,c);
        else if(x==b)
            swap(b,c);
        if(a*a+b*b==c*c)
            printf("Scenario #%d:\nyes\n\n",id);
        else
            printf("Scenario #%d:\nno\n\n",id);
    }
    return 0;
}
