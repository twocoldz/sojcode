#include <iostream>
#include <cstdio>
#define modd 19871118
using namespace std;

int Cal(int n,int m)
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return m;
    }
    if(n%2==0)
    {
        int t=Cal(n/2,m);
        return ((long long )t*(long long)t)%modd;
    }
    else
    {
        int t=Cal(n/2,m);
        return ((long long)t*(long long)t*(long long)m)%modd;
    }
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n)
    {
        if(m==1&&n!=1)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",((long long)m*(long long)Cal(n-1,m-1))%modd);
    }
    return 0;
}
