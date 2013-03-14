#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int a[50005];
int lmax[50005],rmax[50005];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int pre=0;
		lmax[0]=-0x7fffffff;
		for(i=1;i<=n;i++)
		{
			pre=pre>=0?pre+a[i]:a[i];
			lmax[i]=pre>lmax[i-1]?pre:lmax[i-1];
		}
		pre=0;
		rmax[n+1]=-0x7fffffff;
		for(i=n;i>=1;i--)
		{
			pre=pre>=0?pre+a[i]:a[i];
			rmax[i]=pre>rmax[i+1]?pre:rmax[i+1];
		}
		int ans=-0x7fffffff;
		for(i=0;i<=n;i++)
		{
			if(lmax[i]+rmax[i+1]>ans)
				ans=lmax[i]+rmax[i+1];
		}
		printf("%d\n",ans);
	}
	return 0;
}