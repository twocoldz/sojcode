#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int a[10005];

int f(int n)
{
    if(n==1)
        return a[0];
    else if(n==2)
        return a[1];
    else if(n==3)
        return a[0]+a[1]+a[2];
    else
        return min(a[0]+a[1]+a[1]+a[n-1],a[0]+a[0]+a[n-1]+a[n-2])+f(n-2);
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        int sum=f(n);
        printf("%d\n",sum);
    }
    return 0;
}
