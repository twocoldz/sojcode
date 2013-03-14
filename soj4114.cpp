#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[50005];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,n;
		int flag=1;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		for(i=1;i<n;i++)
		{
			while(i<n&&a[i]==a[i+1])
			{
				i++;
			}
			if(i+2<=n)
			{
				if(a[i+1]-a[i]==1&&a[i+2]-a[i]==1)
					continue;
				else
				{
					flag=0;
					break;
				}
			}
			else if(i+1==n)
			{
				if(a[i+1]-a[i]==1)
				{
					continue;
				}
				else
				{
					flag=0;
					break;
				}
			}
			else
			{
				break;	
			}
		}
		if(flag)
		{
			printf("possible\n");
		}
		else
		{
			printf("impossible\n");
		}
	}
	return 0;
}