/*
设mow[i]表示如果你在进入第i个城市之前，有1块钱，
那么在之后最多能变成多少块钱，
apw[i]表示如果你在进入第i个城市之前，有1点攻击力，
那么在之后最多会演化成多少块钱，
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 1e15

using namespace std;
const int maxn=121111+2;
double a[maxn],b[maxn];
double mow[maxn],apw[maxn];

int main()
{
    int n;
    double X,Y;
    while(scanf("%d%lf%lf",&n,&X,&Y)==3)
    {
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",a+i,b+i);
        if(n==0)
        {
            printf("%.0lf\n",X);
            continue;
        }
        mow[n]=max(1.0*b[n]/a[n],1.0);
        apw[n]=b[n];
        for(int i=n-1;i>=0;i--)
        {
            apw[i]=apw[i+1]+b[i]*mow[i+1];
            mow[i]=max(b[i]/a[i]*mow[i+1]+apw[i+1]/a[i],mow[i+1]);
        }
        double ans=X*mow[1]+Y*apw[1];
        if(ans>=inf)
            printf("abm win.\n");
        else
            printf("%.0lf\n",ans);
    }
    return 0;
}
