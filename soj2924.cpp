#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int m[10005];
int p[100060];
int b[10005];

int main()
{
	int n;
	__int64 ans=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m[i]);
			b[i]=m[i];
		}
		sort(m+1,m+1+n);
		for(i=1;i<=n;i++)
		{
			ans+=(__int64)m[i]*(__int64)(i);
			p[m[i]]=i;
		}
		int t=0;
		for(i=1;i<=n;i++)
		{
			if(p[b[i]]!=i)
			{
				t=1;
				if(b[p[b[i]]]!=m[i])
				{
					t=2;
					break;
				}
			}
		}
		printf("%lld\n",ans);
		printf("%d\n",t);
	}
	return 0;
}