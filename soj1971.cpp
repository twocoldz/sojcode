#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int gcd(int a,int b)
{
	while(b)
	{
		int temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}

int main()
{
	double x,y;
	while(scanf("%lf%lf",&x,&y)==2)
	{
		if(x==0&&y==0)
			break;
		int a=x*100+0.5;
		int b=y*100+0.5;
		int ans=a>=b?gcd(a,b):gcd(b,a);
		printf("%d\n",a*b/(ans*ans));
	}
	return 0;
}
