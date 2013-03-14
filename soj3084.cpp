#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[1002][1002][5]; //dp[i][j][k]表示在前i块中取j块，最后状态为k的最优值
/*
t=max(dp[i-1][j][0--4])
t1=max(dp[i-1][j-1][0--4])
case1 k=0;  表示这个位置上下都没取
{
    dp[i][j][0]=t+a[i].y+b[i].y;
}
case2 k=1;  表示这个位置只取了上面
{
    dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j][4],t1)+a[i].x+b[i].y;
}
case3 k=2; 表示这个位置只取了下面
{
    dp[i][j][2]=max(dp[i-1][j][2],dp[i-1][j][4],t1)+a[i].y+b[i].x;
}
case4 k=3;表示上下都取了，并且属于同一块
{
    dp[i][j][3]=max(dp[i-1][j][3],t1)+a[i].x+b[i].x;
}
case5 k=4; 表示上下都取了 但不属于同一块
{
    dp[i][j][4]=max(dp[i-1][j][4],dp[i-1][j-1][1],dp[i-1][j-1][2])+a[i].x+b[i].x;
    if(j>=2)
    {
        dp[i][j][4]=max(dp[i][j][4],t2+a[i].x+b[i].x);
    }
}
*/

struct cake
{
    int x,y;
};

cake a[1002],b[1002];

inline int max3(int a,int b,int c)
{
    return max(max(a,b),c);
}

inline int max5(int a,int b,int c,int d,int e)
{
    return max(max3(a,b,c),max(d,e));
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&b[i].x,&b[i].y);
        }
        memset(dp,0,sizeof(dp));
        dp[1][0][0]=a[1].y+b[1].y;
        for(int i=2;i<=n;i++)
        {
            dp[i][0][0]=dp[i-1][0][0]+(a[i].y+b[i].y);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int t2;
                int t=max5(dp[i-1][j][0],dp[i-1][j][1],dp[i-1][j][2],dp[i-1][j][3],dp[i-1][j][4]);
                int t1=max5(dp[i-1][j-1][0],dp[i-1][j-1][1],dp[i-1][j-1][2],dp[i-1][j-1][3],dp[i-1][j-1][4]);
                if(j>=2)
                {
                    t2=max5(dp[i-1][j-2][0],dp[i-1][j-2][1],dp[i-1][j-2][2],dp[i-1][j-2][3],dp[i-1][j-2][4]);
                }
                dp[i][j][0]=t+a[i].y+b[i].y;
                dp[i][j][1]=max3(dp[i-1][j][1],dp[i-1][j][4],t1)+a[i].x+b[i].y;
                dp[i][j][2]=max3(dp[i-1][j][2],dp[i-1][j][4],t1)+a[i].y+b[i].x;
                dp[i][j][3]=max(dp[i-1][j][3],t1)+a[i].x+b[i].x;
                dp[i][j][4]=max3(dp[i-1][j][4],dp[i-1][j-1][1],dp[i-1][j-1][2])+a[i].x+b[i].x;
                if(j>=2)
                {
                    dp[i][j][4]=max(dp[i][j][4],t2+a[i].x+b[i].x);
                }
                if(j<2)
                {
                    dp[i][j][4]=-1100000000;
                }
                //printf("i=%d j=%d\n",i,j);
                //for(int k=0;k<5;k++)
                //{
                //    printf("k=%d  dp[i][j][k]=%d\n",k,dp[i][j][k]);
                //}
            }
        }
        //int ans=0;
        //for(int i=0;i<=m;i++)
        //{
            int temp=max5(dp[n][m][0],dp[n][m][1],dp[n][m][2],dp[n][m][3],dp[n][m][4]);
            //if(ans<temp)
            //{
              //  ans=temp;
            //}
        //}
        printf("%d\n",temp);
    }
    return 0;
}
