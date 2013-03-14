#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define  MAX 0x7fffffff

int a[2005];
int c[2005][680];

inline int Cal(int x)
{
	return x*x;
}

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)==2)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		memset(c,0,sizeof(c));
		c[0][0]=0;
		c[1][0]=0;
		for(i=1;i<=k;i++)
             c[0][i] = c[1][i] = MAX;
		for(i=2;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(c[i-2][j-1]==MAX)
				{
					c[i][j]=c[i-1][j];
					continue;
				}
				if(c[i-2][j-1]+Cal(a[i]-a[i-1])<c[i-1][j])
				{
					c[i][j]=c[i-2][j-1]+Cal(a[i]-a[i-1]);
				}
				else
				{
					c[i][j]=c[i-1][j];
				}
			}
		}
		printf("%d\n",c[n][k]);
	}
	return 0;
}