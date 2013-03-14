#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int x,deg;
}a[10005];

bool cmp(node a,node b)
{
    return a.x<b.x;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i].x),a[i].deg=0;
        int e,b;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&b,&e);
            a[b].deg++;
            a[e].deg--;
        }
        sort(a+1,a+1+n,cmp);
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(a[i].deg>0)
            {
                ans+=a[i].deg*(a[i+1].x-a[i].x);
                a[i+1].deg+=a[i].deg;
                a[i].deg=0;
            }
            else if(a[i].deg<0)
            {
                ans+=a[i].deg*(a[i].x-a[i+1].x);
                a[i+1].deg+=a[i].deg;
                a[i].deg=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
