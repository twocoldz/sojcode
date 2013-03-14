#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int a[1005];
int gcd(int x,int y)
 {
     return x==0?y:gcd(y%x,x);
 }

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        int aa,bb;
        scanf("%d%d",&aa,&bb);
        int Max=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            a[i]*=6;
            Max=max(Max,a[i]);
        }
        int ans=inf;
        for(int i=Max/3;i<=Max;i++)
        {
            int t1=0,t2=0;
            for(int j=1;j<=n;j++)
            {
                t1+=(a[j]+i-1)/i;
                t2+=(a[j]+i-1)/i*i-a[j];
            }
            ans=min(ans,aa*t2+bb*t1*6);
        }
        int t=gcd(ans,6);
        if(t==6)
        {
            printf("%d\n",ans/6);
        }
        else
        {
            printf("%d / %d\n",ans/t,6/t);
        }
    }
    return 0;
}
