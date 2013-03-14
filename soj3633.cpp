/*
��mow[i]��ʾ������ڽ����i������֮ǰ����1��Ǯ��
��ô��֮������ܱ�ɶ��ٿ�Ǯ��
apw[i]��ʾ������ڽ����i������֮ǰ����1�㹥������
��ô��֮�������ݻ��ɶ��ٿ�Ǯ��
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
