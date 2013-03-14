#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int x,y,pos;
    double z;
}a[10005];
int ans[10005];
bool cmp(node a,node b)
{
    return a.z>b.z;
}

int main()
{
    int F,M,n;
    while(scanf("%d%d%d",&F,&M,&n)==3)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].x,&a[i].y),a[i].pos=i,a[i].z=1.0*a[i].x/a[i].y;
        sort(a+1,a+1+n,cmp);
        double x=F*1.0;
        double y=M*1.0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if((x+a[i].x)/(y+a[i].y)>x/y)
            {
                x+=a[i].x;
                y+=a[i].y;
                ans[cnt++]=a[i].pos;
            }
        }
        if(cnt==0)
            printf("NONE\n");
        else
        {
            sort(ans,ans+cnt);
            for(int i=0;i<cnt;i++)
                printf("%d\n",ans[i]);
        }
    }
    return 0;
}
