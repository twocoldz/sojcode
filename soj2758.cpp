#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

struct Node
{
    int x,y,num;
};

bool vis[1005][1005];
char map[1005][1005];
int n,m,ans;

inline bool Check(Node t)
{
    if(t.x<0||t.x>=n||t.y<0||t.y>=m||map[t.x][t.y]=='#')
        return false;
    return true;
}

void Bfs(int sx,int sy)
{
    memset(vis,0,sizeof(vis));
    queue<Node>q;
    Node t;
    t.x=sx,t.y=sy,t.num=0;
    vis[sx][sy]=1;
    q.push(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            Node tt;
            tt.x=t.x,tt.y=t.y;
            while(true)
            {
                tt.x+=dx[i],tt.y+=dy[i];
                if(Check(tt))
                {
                    if(!vis[tt.x][tt.y])
                    {
                        if(map[tt.x][tt.y]=='t')
                        {
                            ans=t.num+1;
                            return ;
                        }
                        vis[tt.x][tt.y]=1;
                        tt.num=t.num+1;
                        q.push(tt);
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    return ;
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        int sx,sy;
        for(int i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='r')
                {
                    sx=i,sy=j;
                }
            }
        }
        ans=-1;
        Bfs(sx,sy);
        printf("%d\n",ans);
    }
    return 0;
}
