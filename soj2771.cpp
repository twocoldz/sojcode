/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int dx[5]={1,1,0,-1,-1};
const int dy[5]={1,0,1,1,0};
int m,flag;
int a[8][8];
bool vis[8][8];

inline bool Check(int x,int y)
{
    if(x<0||x>=8||y<0||y>=8)
        return false;
    return true;
}

void Dfs(int x,int y,int sum)
{
    if(x==7&&y==7)
    {
        if(sum==m)
        {
            flag=1;
        }
        return ;
    }
    if(sum>m)
        return ;
    for(int i=0;i<5;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(Check(nx,ny)&&!vis[nx][ny])
        {
            vis[nx][ny]=1;
            Dfs(nx,ny,sum+a[nx][ny]);
            vis[nx][ny]=0;
            if(flag==1)
                return ;
        }
    }
}

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&m);
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                scanf("%d",a[i]+j);
        flag=0;
        memset(vis,0,sizeof(vis));
        vis[0][0]=1;
        Dfs(0,0,a[0][0]);
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool B[8][8];
int C[8][8];
int MX[8][8], MN[8][8];
int dx[] = {-1, -1, 1, 1, 0};
int dy[] = {0, 1, 0, 1, 1};

bool dfs(int x, int y, int rem)
{
    if(rem == 0)
        return x == 7 && y == 7;
    for(int d = 0; d < 5; ++d)
    {
        x += dx[d];
        y += dy[d];
        if(x >= 0 && x < 8 && y >= 0 && y < 8 && !B[x][y]
            && C[x][y] <= rem
            && (MN[x][y] == -1 || MN[x][y] <= rem)
            && (MX[x][y] == -1 || MX[x][y] >= rem))
        {
            B[x][y] = true;
            if(dfs(x, y, rem - C[x][y])) return true;
            B[x][y] = false;
        }
        x -= dx[d];
        y -= dy[d];
    }
    return false;
}

int main()
{
    int T, rem;
    for(cin >> T; T--;)
    {
        cin >> rem;
        memset(B, 0, sizeof(B));
        memset(MN, -1, sizeof(MN));
        memset(MX, -1, sizeof(MX));
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j)
                cin >> C[i][j];
        B[0][0] = true;
        //cnt = 0;
        puts(dfs(0, 0, rem - C[0][0]) ? "Yes" : "No");
    }
}
