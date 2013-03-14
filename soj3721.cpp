#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int d,s,e;
    bool operator <(const node& a) const
    {
        if(d==a.d)
        {
            if(e==a.e)
                return s<a.s;
            else
                return e<a.e;
        }
        else
            return d<a.d;
    }
}a[50005];

int main()
{
    int cases;
    scanf("%d",&cases);
    for(int id=1;id<=cases;id++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&a[i].d,&a[i].s,&a[i].e);
        sort(a,a+n);
        //for(int i=0;i<n;i++)
        //    printf("%d %d %d\n",a[i].d,a[i].s,a[i].e);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans++;
            int j=i;
            while((i+1<n)&&((a[i+1].d<a[j].d)||(a[i+1].d==a[j].d&&a[i+1].s<a[j].e)))
                i++;
        }
        printf("Scenario #%d:\n%d\n\n",id,ans);
    }
    return 0;
}
