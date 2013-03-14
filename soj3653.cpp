#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
struct node
{
    long long c,num;
    //double v;
}clo[100005];

bool cmp(node a,node b)
{
    return a.c<b.c;
}

int main()
{
    int  n;
    long long B;
    while(scanf("%d%lld",&n,&B)==2)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&clo[i].c,&clo[i].num);
            //clo[i].v=double(clo[i].num)/double(clo[i].c);
        }
        sort(clo,clo+n,cmp);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            if(B==0)
                break;
            if(clo[i].c>B)
                continue;
            long long t=min(clo[i].num,B/clo[i].c);
            sum+=t;
            B-=t*clo[i].c;
            //printf("t=%d B=%lld\n",t,B);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
