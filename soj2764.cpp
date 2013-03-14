#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
bool vis[105][105];
int mk[105][105];
char map[105][105];
int n,m;

inline bool Judge(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m)
        return 0;
    return 1;
}

bool Hungary(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(Judge(tx,ty)&&!vis[tx][ty]&&(map[x][y]==map[tx][ty]))
        {
            vis[tx][ty]=1;
            if(mk[tx][ty]==-1||Hungary(mk[tx][ty]/m,mk[tx][ty]%m))
            {
                mk[tx][ty]=x*m+y;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
            scanf("%s",map[i]);
        memset(mk,-1,sizeof(mk));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                memset(vis,0,sizeof(vis));
                if(Hungary(i,j))
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
