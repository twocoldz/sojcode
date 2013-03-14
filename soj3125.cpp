#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int i,n,m;
	long long sum;
	int a[100005];
	while(scanf("%d%d",&n,&m)!=EOF&&n)
	{
		for(sum=0,i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum<m)
		{
			sum=-1;
			cout<<sum<<endl;
			continue;
		}
		if(sum==m)
		{
			cout<<n<<endl;
			continue;
		}
		sort(a+1,a+n+1);
		for(i=n,sum=1;i>=1;i--,sum++)
		{
			m-=a[i];
			if(m<=0)
			{
				cout<<sum<<endl;
				break;
			}
		}
	}
	return 0;
}