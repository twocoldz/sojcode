#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define max(a,b) a>b?a:b

long long dp[1005];

void make()
{
	int i,j,k;
	for( k=0;k<=1000;k++)
		dp[k]=1;
	for(i=2;i<=32;i++)
	{
		for(j=i*i;j<=1000;j++)
		{
			dp[j]=dp[j-i*i]+dp[j];
		}
	}
}

int main()
{
	int n;
	make();
	while(scanf("%d",&n)==1&&n)
	{
		printf("%lld\n",dp[n]);
	}
	return 0;
}