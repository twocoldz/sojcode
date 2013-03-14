#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int cases;
    bool vis[15];
    int times[15];
    scanf("%d",&cases);
    while(cases--)
    {
        int n,m;
        memset(vis,0,sizeof(vis));
        memset(times,0,sizeof(times));
        scanf("%d%d",&n,&m);
        int H,M;
        char a[2],b[5];
        int tot=0,ans=0;
        while(m--)
        {
            scanf("%d:%d %s %s",&H,&M,a,b);
            if(b[0]=='Y')
            {
                if(!vis[a[0]-'A'])
                {
                    tot+=(times[a[0]-'A']*20+H*60+M);
                    vis[a[0]-'A']=1;
                    ans++;
                }
            }
            else
            {
                if(!vis[a[0]-'A'])
                {
                    times[a[0]-'A']++;
                }
            }
        }
        printf("%d %d\n",ans,tot);
    }
    return 0;
}
