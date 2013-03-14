#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int a[10];

void Init()
{
    a[0]=1;
    for(int i=1;i<=9;i++)
        a[i]=a[i-1]*10;
}

int main()
{
    int n,m;
    Init();
    while(scanf("%d%d",&n,&m)==2)
    {
        int t=n%a[m];
        if(t*2<a[m])
            n-=t;
        else
            n=n-t+a[m];
        printf("%d\n",n);
    }
    return 0;
}
