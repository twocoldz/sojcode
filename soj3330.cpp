#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
struct node
{
    int x,y;
};
queue<node> q;
int f[1002][1002];
int n,m,sum;

bool Check(node t)
{
    if(t.x<0||t.x>=n||t.y<0||t.y>=m)
        return false;
    return true;
}

void Bfs()
{
    while(!q.empty())
    {
        node t=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            node tt;
            tt.x=t.x+dx[i],tt.y=t.y+dy[i];
            if(Check(tt)&&f[tt.x][tt.y]==-1)
            {
                f[tt.x][tt.y]=f[t.x][t.y]+1;
                sum+=f[tt.x][tt.y];
                q.push(tt);
            }
        }
    }
}

int main()
{
    int cases;
    char x[2500];
    scanf("%d",&cases);
    while(cases--)
    {
        while(!q.empty())
            q.pop();
        scanf("%d%d",&n,&m);
        node k;
        getchar();
        for(int i=0;i<n;i++)
        {
            gets(x);
            //printf("%s\n",x);
            for(int j=0;j<m;j++)
            {
                if(x[j*2]=='1')
                {
                    k.x=i,k.y=j;
                    q.push(k);
                    f[i][j]=0;
                }
                else
                {
                    f[i][j]=-1;
                }
            }
        }
        sum=0;
        //puts("?");
        Bfs();
        //for(int i=0;i<n;i++)
        //    for(int j=0;j<m;j++)
        //        sum+=f[i][j];//printf("f[%d][%d]=%d\n",i,j,f[i][j]);
        printf("%d\n",sum);
    }
    return 0;
}
