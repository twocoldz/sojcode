#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n;
	int cases=1;
	while(scanf("%d",&n)==1&&n)
	{
		double Min=0x7fffffff;
		double temp;
		int wch,d,p,i;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&d,&p);
			temp=double(p)/(double(d)*double(d));
			if(temp<Min)
			{
				Min=temp;
				wch=d;
			}
		}
		printf("Menu %d: %d\n",cases++,wch);
	}
	return 0;
}