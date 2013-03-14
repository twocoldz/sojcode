#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int f[1000005];

void make()
{
	int i;
	for(i=1;i<=1000004;i++)
		f[i]=1;
	for(i=2;i<=sqrt(1000000);i++)
	{
		for(int j=i;i*j<=1000000;j++)
		{
			f[i*j]=f[i]+f[j];
		}
	}
	for(i=3;i<=1000000;i++)
		f[i]+=f[i-1];
}

int main()
{
	int i,n;
	make();
	while(scanf("%d",&n)==1)
	{
		if(n==0||n==1)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n",f[n]);
	}
	return 0;
}