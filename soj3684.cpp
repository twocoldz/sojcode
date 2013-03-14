#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
struct node
{
    double x,y;
    double ang;
}p[100005];

bool Check(node a,node b)
{
    return a.x*b.y<b.x*a.y;
}

bool cmp(node a,node b)
{
    return a.ang<b.ang;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            p[i].ang=atan2(p[i].x,p[i].y);
        }
        sort(p,p+n,cmp);
        //for(int i=0;i<n;i++)
        //    printf("%lf\n",p[i].ang);
        int j=1;
        long long ans=(long long)n*(n-1)*(n-2)/6;
        for(int i=0;i<n;i++)
        {
            while(Check(p[i],p[j]))
                j=(j+1)%n;
            long long m=(j-i-1+n)%n;
            ans-=(m*(m-1))/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
