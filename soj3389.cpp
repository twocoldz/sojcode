#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int lcm=a>=b?gcd(a,b):gcd(b,a);
        printf("%d %d %d\n",i,a*b/lcm,lcm);
    }
    return 0;
}
