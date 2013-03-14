#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int a[100];
bool vis[100];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n+m)
    {
        if((m*(m-1)/2)<n)
        {
            puts("N");
            continue;
        }
        memset(vis,0,sizeof(vis));
        int tot=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",a+i);
            for(int j=1;j<i;j++)
            {
                if(!vis[abs(a[i]-a[j])])
                    vis[abs(a[i]-a[j])]=1,tot++;
            }
        }
        if(tot==n)
            puts("Y");
        else
            puts("N");
    }
    return 0;
}
