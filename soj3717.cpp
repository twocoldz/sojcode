#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
bool vis[2][15005];
int a[105];

int main()
{
    int cases;
    scanf("%d",&cases);
    for(int id=1;id<=cases;id++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int ma=0;
        a[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i),ma=max(ma,a[i]);
        memset(vis,0,sizeof(vis));
        vis[0][0]=1;
        int len=0;
        int r=0;
        for(int i=1;i<=m;i++)
        {
            r^=1;
            for(int j=len;j>=0;j--)
            {
                if(vis[r^1][j])
                {
                    for(int k=0;k<=n;k++)
                    {
                        if(a[k]!=ma)
                        {
                            vis[r][j+a[k]]=vis[r][j+a[k]*2]=vis[r][j+3*a[k]]=1;
                            len=max(len,j+3*a[k]);
                        }
                        else
                        {
                            vis[r][j+a[k]]=vis[r][j+a[k]*2]=1;
                            len=max(len,j+a[k]*2);
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<=len;i++)
            if(vis[r][i])
                ans++;
        printf("Scenario #%d:\n%d\n\n",id,ans);
    }
    return 0;
}
