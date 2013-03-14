#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;
struct Food{
	int p,s;
}food[10007];
int dp[20010];
int main(void)
{
	int test,i,j,k;
	scanf("%d",&test);
	int h,p;
	while(test--)
	{
		scanf("%d%d",&h,&p);
		int sum=0;
		for(i=0;i<p;i++)
		{
			scanf("%d%d",&food[i].p,&food[i].s);
			sum+=food[i].s;
		}
		if(sum<=h)
		{
			puts("0");
			continue;
		}
		memset(dp,0x7fffffff,sizeof(dp));
		dp[0]=0;
		for(i=0;i<p;i++)
		{
			for(j=h;j>=0;j--)
			{
				if(dp[j]!=-1)
				{
					int t=j+food[i].p;
					if(t>h)
						t=h;
					if(dp[t]==-1||dp[t]>food[i].s+dp[j])
					{
						dp[t]=food[i].s+dp[j];
					}
				}
			}
		}
		if(dp[h]==-1)
			puts("0");
		else
			printf("%d\n",sum-dp[h]);
	}
	return 0;
}
