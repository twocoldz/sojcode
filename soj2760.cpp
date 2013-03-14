#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)==2)
	{
		__int64 ans1,ans2,ans;
		if(a%2==0)
		{
			ans1=a/2*(a+1);
		}
		else
		{
			ans1=(a+1)/2*a;
		}
		if(b%2==0)
		{
			ans2=b/2*(b+1);
		}
		else
		{
			ans2=(b+1)/2*b;
		}
		ans=ans1*ans2;
	
		printf("%lld\n",ans);
	}
	return 0;
}