#include <cstdio>
#include <cmath>

using namespace std;
int a[1000005];

void Init()
{
    a[0]=1;
    for(int i=1;i<=1000000;i++)
        a[i]=(a[(int)(i-sqrt(i))]+a[int(log(i))]+a[int(i*sin(i)*sin(i))])%1000000;
}

int main()
{
    Init();
    int n;
    while(scanf("%d",&n)&&n!=-1)
    {
        printf("%d\n",a[n]);
    }
    return 0;
}
