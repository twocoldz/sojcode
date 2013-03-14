#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int pos;
    long long num;
}a[100005];

bool cmp(node a,node b)
{
    return a.pos<b.pos;
}

long long min(long long a,long long b)
{
    return a<b?a:b;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        long long sum=0;
        for(int i=0;i<n;i++)
            scanf("%d%lld",&a[i].pos,&a[i].num),sum+=a[i].num;
        sort(a,a+n,cmp);
        for(int i=0;i<n-1;i++)
            sum-=min(a[i].num,a[i+1].num);
        printf("%lld\n",sum);
    }
    return 0;
}
