#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 101;
const int M = 101;
int d[4][2] = {0,1,0,-1,1,0,-1,0};
int dp[N][N];
int map[N][N];
int r,c;
int Dp(int x, int y)
{
   if(dp[x][y])
      return dp[x][y];
   int m = 0;
   for(int i = 0; i < 4; i++)
   {
      int x1 = x + d[i][0];
      int y1 = y + d[i][1];
      if(x1 >= 0 && y1 >= 0 && x1 < r && y1 < c && map[x1][y1] > map[x][y])
      {
         m = max(Dp(x1,y1),m);
      }
   }
   dp[x][y] = m + 1;
   return m+1;
}
int main()
{
   while(scanf("%d%d",&r,&c))
   {
      if(r==0&&c==0)
         break;
      for(int i = 0; i < r; i++)
      {
         for(int j = 0; j < c; j++)
         {
            scanf("%d",map[i]+j);
         }
      }
      int ans = 0;
      memset(dp,0,sizeof(dp));
      for(int i = 0; i < r; i++)
      {
         for(int j = 0; j < c; j++)
         {
            ans = max(ans,Dp(i,j));
         }
      }
      printf("%d\n",ans-1);
   }
   return 0;
}
