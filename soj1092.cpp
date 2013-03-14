#include <iostream>
#include <cstdio>
using namespace std;

int x,y;

void extended_euclid(int a,int b)
{
	int temp;
	if(b==0)
	{
		x=1,y=0;
	}
	else
	{
		extended_euclid(b,a%b);
		temp=x;
		x=y;
		y=temp-a/b*y;
	}
}

int main()
{
	int a,n;
	while(scanf("%d%d",&a,&n)==2&&(n|a))
	{
		extended_euclid(a,n);
		printf("%d\n",(x%n+n)%n);
	}
	return 0;
}