#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int dx1[8]={1,2,2,1,-1,-2,-2,-1};
const int dy1[8]={-2,-1,1,2,2,1,-1,-2};
const int dx2[4]={2,0,-2,0};
const int dy2[4]={0,2,0,-2};
struct P
{
    int x,y,s;
}t;
queue<P> v;
int dp[55][55][2];
int r,c;
int sx,sy,ex,ey;

bool Check(int i,int j)
{
    if(i<0||i>=r||j<0||j>=c)
        return false;
    return true;
}

void Bfs()
{
    dp[sx][sy][1]=0;
    while(!v.empty())
        v.pop();
    t.x=sx,t.y=sy,t.s=1;
    v.push(t);
    while(!v.empty())
    {
        t=v.front();
        v.pop();
        int tx=t.x;
        int ty=t.y;
        int sta=t.s;
        //printf("tx=%d ty=%d\n",tx,ty);
        if(sta==1)
        {
            for(int i=0;i<8;i++)
            {
                if(Check(tx+dx1[i],ty+dy1[i])&&dp[tx+dx1[i]][ty+dy1[i]][0]==-1)
                {
                    dp[tx+dx1[i]][ty+dy1[i]][0]=dp[tx][ty][1]+1;
                    if(tx+dx1[i]==ex&&ty+dy1[i]==ey)
                        return ;
                    t.x=tx+dx1[i],t.y=ty+dy1[i],t.s=0;
                    v.push(t);
                }
            }
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                if(Check(tx+dx2[i],ty+dy2[i])&&dp[tx+dx2[i]][ty+dy2[i]][1]==-1)
                {
                    dp[tx+dx2[i]][ty+dy2[i]][1]=dp[tx][ty][0]+1;
                    if(tx+dx2[i]==ex&&ty+dy2[i]==ey)
                        return ;
                    t.x=tx+dx2[i],t.y=ty+dy2[i],t.s=1;
                    v.push(t);
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d",&r,&c)==2)
    {
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        sx--,sy--,ex--,ey--;
        if(sx==ex&&sy==ey)
        {
            printf("0\n");
            continue;
        }
        memset(dp,-1,sizeof(dp));
        Bfs();
        if(dp[ex][ey][0]==-1)
            printf("%d\n",dp[ex][ey][1]);
        else
            printf("%d\n",dp[ex][ey][0]);
    }
    return 0;
}
