#include <cstdio>
#include <algorithm>

using namespace std;
int a[10005];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=m;i++)
            scanf("%d",a+i);
        sort(a+1,a+1+m);
        int ans=max(a[1],n-a[m]);
        for(int i=1;i<m;i++)
        {
            ans=max(ans,(a[i+1]-a[i])/2);
        }
        printf("%d\n",ans);
    }
    return 0;
}
