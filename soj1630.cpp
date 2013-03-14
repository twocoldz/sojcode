#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int i,n,a,b;
		scanf("%d",&n);
		scanf("%d",&a);
		for(i=1;i<n;i++)
		{
			scanf("%d",&b);
			a=(double)a*b/gcd(a,b);
		}
		cout<<a<<endl;
	}
	return 0;
}