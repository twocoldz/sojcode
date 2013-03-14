#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

//#define  min(a,b) a<b?a:b

using namespace std;

const int maxn=301;
int n;

int num[maxn][maxn];
int dp[maxn][maxn][9][9];

void RMQ_2D_pre()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j][0][0]=num[i][j];
		}
	}
	int m=log(double(n))/log(2.0);

	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0&&j==0)
				continue;
			for(int row=1;row+(1<<i)-1<=n;row++)
			{
				for(int col=1;col+(1<<j)-1<=n;col++)
				{
					if(i==0)
						dp[row][col][i][j]=min(dp[row][col][i][j-1],dp[row][col+(1<<(j-1))][i][j-1]);
					else
						dp[row][col][i][j]=min(dp[row][col][i-1][j],dp[row+(1<<(i-1))][col][i-1][j]);
				}
			}
		}
	}
}

int RMQ_2D_query(int x1,int x2 ,int y1,int y2)
{
	int kx = log(double(x2 - x1 +1)) / log(2.0);
	int ky = log(double(y2 - y1 +1)) / log(2.0);
	int m1 = dp[x1][y1][kx][ky];
	int m2 = dp[x2-(1<<kx)+1][y1][kx][ky];
	int m3 = dp[x1][y2-(1<<ky)+1][kx][ky];
	int m4 = dp[x2-(1<<kx)+1][y2-(1<<ky)+1][kx][ky];
    return min( min(m1,m2), min(m3,m4) );
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%d",&num[i][j]);
		}
		RMQ_2D_pre();
		int q,x1,x2,y1,y2;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%d\n",RMQ_2D_query(x1,x2,y1,y2));
		}
	}
	return 0;
}