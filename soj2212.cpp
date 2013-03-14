#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)==2&&n)
	{
		int ans=n;
		while(n>=k)
		{
			ans+=n/k;
			n=n%k+n/k;
		}
		cout<<ans<<endl;
	}
	return 0;
}