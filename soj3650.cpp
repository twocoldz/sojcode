#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
int a[6000],b[6000];
int p,q;

int main()
{
    while(scanf("%d%d",&p,&q)==2)
    {
        int i,t=0;
        for(i=1;i<=sqrt(p);i++)
        {
            if(p%i==0)
            {
                a[t++]=i;
                //printf("%d\n",a[t-1]);
            }
        }
        for(i=t-1;i>=0;i--)
        {
            if(p/a[i]!=a[i])
            {
                a[t++]=p/a[i];
            }
        }
        int len=t;
        t=0;
        for(i=1;i<=sqrt(q);i++)
        {
            if(q%i==0)
            {
                b[t++]=i;
            }
        }
        for(i=t-1;i>=0;i--)
        {
            if(q/b[i]!=b[i])
            {
                b[t++]=q/b[i];
            }
        }
        //printf("tt");
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<t;j++)
            {
                printf("%d %d\n",a[i],b[j]);
            }
        }
    }
    return 0;
}
