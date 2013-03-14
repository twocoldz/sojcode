/*题目意思是说有一条路（单向） 左右各有有一些车要过这条路，对于每一边，你不能改变车的出发顺序。
你只能改变某一时刻，先左边发车还是先右边发车。
dp[i][j][K]表示左边过了I辆，右边过了J辆，K=0表示最后一辆是左边开出的，K=1表示从右边开出。
由题目意思，如果两辆车同向，则后一辆车的出发时间为ST=MAX(自身出发时间，前一辆车出发时间+10），
后一辆车的到达时间为MAX(前一辆车到达时间+10，ST）。

本来我想直接用dp[i][j][0]和dp[I][J][1]分别来更新DP[I+1][J][0]和DP[I][J+1][1]，
但是做了以后发现一个问题，如果有几辆车都是同向，当前车的出发时间没法确定。
因为当前车的出发时间跟前面一辆车有关，而前面一辆车的出发时间可能跟再前面一辆有关。
例如样例中：
A 0 100
B 50 100
A 100 1
A 170 100

假如我们不看第二辆车。那么第一辆车在100的时候到达，第三辆车最早在110的时候到达，但是第三辆车最早出发时间是10！！！
从而第四辆车在20的时候就可以出发了。
如果按我的方法做，那么会认为第三辆车的出发时间是109！！这样第四辆车要219的时候才能到！

改进方法：
用dp[I][J][0]来更新DP[I][J+X][1],用DP[I][J][1]来更新DP[I+X][J][0]，表示同一个方向连续开了X辆车。*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
int dp[205][205][2];
struct node
{
    int t,d;
}l[205],r[205];

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n,t,d;
        int a=0,b=0;
        char dir[2];
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s %d %d",dir,&t,&d);
            if(dir[0]=='A')
            {
                l[++a].t=t;
                l[a].d=d;
            }
            else
            {
                r[++b].t=t;
                r[b].d=d;
            }
        }
        memset(dp,inf,sizeof(dp));
        dp[0][0][0]=dp[0][0][1]=0;
        int bt;
        for(int i=0;i<=a;i++)
        {
            for(int j=0;j<=b;j++)
            {
                if(dp[i][j][0]!=inf)
                {
                    bt=max(dp[i][j][0],r[j+1].t);
                    dp[i][j+1][1]=min(dp[i][j+1][1],bt+r[j+1].d);
                    //printf("dp[%d][%d]=%d\n",i,j+1,dp[i][j+1][1]);
                    for(int k=j+2;k<=b;k++)
                    {
                        bt=max(bt+10,r[k].t);
                        int tt=max(bt+r[k].d,dp[i][k-1][1]+10);
                        dp[i][k][1]=min(dp[i][k][1],tt);
                    }
                }
                if(dp[i][j][1]!=inf)
                {
                    bt=max(dp[i][j][1],l[i+1].t);
                    dp[i+1][j][0]=min(dp[i+1][j][0],bt+l[i+1].d);
                    //printf("dp[%d][%d]=%d\n",i+1,j,dp[i+1][j][0]);
                    for(int k=i+2;k<=a;k++)
                    {
                        bt=max(bt+10,l[k].t);
                        int tt=max(bt+l[k].d,dp[k-1][j][0]+10);
                        dp[k][j][0]=min(dp[k][j][0],tt);
                    }
                }
            }
        }
        int ans=min(dp[a][b][0],dp[a][b][1]);
        printf("%d\n",ans);
    }
    return 0;
}
