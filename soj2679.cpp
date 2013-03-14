#include <cstdio>
#include <cstring>
#include <algorithm>
int num[10005];
int main()
{
    int s,n,m;
    while(scanf("%d",&s)&&s)
    {
        int x,ans=0;
        memset(num,0,sizeof(num));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&x),num[x]++;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&x);
            if(x<s)
                ans+=num[s-x];
        }
        printf("%d\n",ans);
    }
    return 0;
}
