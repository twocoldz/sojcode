#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int sum=1;
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				n/=i;
				while(n%i==0)
				{
					sum*=i;
					n/=i;
				}
			}
		}
		printf("%d\n",sum+1);
	}
	return 0;
}