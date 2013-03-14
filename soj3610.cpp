#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

#define inf 0x3f3f3f3f

using namespace std;
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};
struct node
{
    int x,y;
};
int map[1005][1005];
char s[2005];
int n,m;
bool vis[1005][1005];
int d[1005][1005];
int sx[1005][1005],sy[1005][1005];

inline int Sq(int x,int y)
{
    return ((x*x)+(y*y));
}

inline bool Judge(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m)
        return false;
    return true;
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&n,&m);
        getchar();
        queue<int> q;

        for(int i=0;i<n;i++)
        {
            gets(s);
            for(int j=0;j<m;j++)
            {
                map[i][j]=s[j*2]-'0';
                if(map[i][j])
                {
                    sx[i][j]=i;
                    sy[i][j]=j;
                    q.push(i*m+j);
                    vis[i][j]=1;
                    d[i][j]=0;
                }
                else
                {
                    d[i][j]=inf;
                    vis[i][j]=0;
                }
            }
        }


        while(!q.empty())
         {
             int y=q.front();
             q.pop();
             int x=y/m;
             y%=m;
             vis[x][y]=false;
             for(int i=0;i<8;i++)
             {
                 int xx=x+dx[i];
                 int yy=y+dy[i];
                 if(Judge(xx,yy))
                 {
                     if(map[xx][yy]==1)
                        continue;
                     int dis=Sq(sx[x][y]-xx,sy[x][y]-yy);
                     if(d[xx][yy]>dis)
                     {
                         d[xx][yy]=dis;
                         sx[xx][yy]=sx[x][y];
                         sy[xx][yy]=sy[x][y];
                         if(!vis[xx][yy])
                         {
                             q.push(xx*m+yy);
                             vis[xx][yy]=true;
                         }
                     }
                 }
             }
         }

        double ans=0.0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(d[i][j])
                    ans+=sqrt(d[i][j]);
        printf("%.03lf\n",ans);
    }
    return 0;
}

/*
while(!q.empty())
        {
            t=q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {
                tt.x=t.x+dx[i];
                tt.y=t.y+dy[i];
                if(map[tt.x][tt.y])
                    continue;
                if(Judge(tt))
                {
                    int dis=Sq(tt.x-sx[t.x][t.y],tt.y-sy[t.x][t.y]);
                    if(dis<d[tt.x][tt.y])
                    {
                        sx[tt.x][tt.y]=sx[t.x][t.y];
                        sy[tt.x][tt.y]=sy[t.x][t.y];
                        d[tt.x][tt.y]=dis;
                        if(!vis[tt.x][tt.y])
                        {
                            vis[tt.x][tt.y]=1;
                            q.push(tt);
                        }
                    }
                }
            }
        }//end while
*/
