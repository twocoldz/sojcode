#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
int mk[1005];
bool vis[1005];
bool fit[1005][1005];
int n;

bool Hungary(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(fit[u][i]&&!vis[i])
        {
            vis[i]=1;
            if(mk[i]==-1||Hungary(mk[i]))
            {
                mk[i]=u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    for(int i=1;i<=1000;i++)
    {
        for(int j=i+1;j<=1000;j++)
        {
            int x=sqrt(i+j);
            if(x*x==i+j)
                fit[i][j]=1;
        }
    }
    while(scanf("%d",&n)&&n)
    {
        int ans=0;
        memset(mk,-1,sizeof(mk));
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(Hungary(i))
                ans++;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
