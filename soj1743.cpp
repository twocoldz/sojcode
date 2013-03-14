#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int Cal(int n)
{
    int ans=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(i*i!=n)
                ans+=2;
            else
                ans+=1;
        }
    }
    return ans;
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a<b)
            swap(a,b);
        printf("%d\n",Cal(gcd(a,b)));
    }
    return 0;
}
