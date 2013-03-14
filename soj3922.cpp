#include <iostream>
#include <cstdio>
#include <cstdio>
#include <algorithm>

using namespace std;
int a[200005];

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		int b[2];
		int i,j;
		for(i=0;i<2*n+2;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+2*n+2);
		for(i=0,j=0;i<2*n+1;i+=2)
		{
			if(a[i]!=a[i+1])
			{
				b[j]=a[i];
				j++;
				if(j==2)
				{
					break;
				}
				i--;
			}
		}
		if(j==1)
		{
			b[1]=a[2*n+1];
		}
		printf("%d %d\n",b[0],b[1]);
	}
	return 0;
}