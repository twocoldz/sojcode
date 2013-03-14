#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int h[105];
int leftf[105],rightf[105];

int main()
{
	int i,j,n,ans;
	while(scanf("%d",&n)==1)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&h[i]);
		memset(leftf,0,sizeof(leftf));
		memset(rightf,0,sizeof(rightf));
		ans=0;
		for(i=n-1;i>=1;i--)
		{
			for(j=i+1;j<=n;j++)
			{
				if(h[i]>h[j]&&leftf[i]<=leftf[j])
					leftf[i]=leftf[j]+1;
			}
		}
		for(i=2;i<=n;i++)
		{
			for(j=i-1;j>=1;j--)
			{
				if(h[i]>h[j]&&rightf[i]<=rightf[j])
					rightf[i]=rightf[j]+1;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(ans<leftf[i]+rightf[i])
				ans=leftf[i]+rightf[i];
		}
		ans++;
		printf("%d\n",n-ans);
	}
	return 0;
}