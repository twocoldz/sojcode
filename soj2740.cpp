#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
#define maxn 50005
int num[maxn],n;
int maxval[maxn][20];
int minval[maxn][20];

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

void maxRmq()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		maxval[i][0]=num[i];
	}
	for(j=1;j<=log((double)(n+1))/log(2.0);j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			maxval[i][j]=max(maxval[i][j-1],maxval[i+(1<<(j-1))][j-1]);
		}
	}
}

void minRmq()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		minval[i][0]=num[i];
	}
	for(j=1;j<=log((double)(n+1))/log(2.0);j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			minval[i][j]=min(minval[i][j-1],minval[i+(1<<(j-1))][j-1]);
		}
	}
}

int qmax(int a,int b)
{
	if(a>b)
		swap(a,b);
	int k=(int)(log((double)(b-a+1))/log(2.0));
	return max(maxval[a][k],maxval[b-(1<<k)+1][k]);
}

int qmin(int a,int b)
{
	if(a>b)
		swap(a,b);
	int k=(int)(log((double)(b-a+1))/log(2.0));
	return min(minval[a][k],minval[b-(1<<k)+1][k]);
}

int main()
{
	int m,i,a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		maxRmq();
		minRmq();
		while(m--)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",qmax(a,b)-qmin(a,b));
		}
	}
	return 0;
}