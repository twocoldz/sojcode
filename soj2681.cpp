#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		int ans=sqrt(2*n+1);
		printf("%d\n",ans);
	}
	return 0;
}
