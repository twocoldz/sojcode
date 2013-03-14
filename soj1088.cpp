#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[101];

void make()
{
	a[1]=7;
	a[2]=8;
	a[3]=15;
	a[4]=12;
	a[5]=9;
	a[6]=16;
	a[8]=13;
	a[10]=20;
	a[13]=17;
	a[16]=14;
	a[20]=21;
	a[26]=18;
	a[32]=15;
	a[33]=25;
	a[41]=22;
	a[65]=16;
	a[52]=19;
	a[83]=23;
	a[67]=26;
	a[53]=29;
}

int main()
{
	memset(a,0,sizeof(a));
//	freopen("out.txt","w",stdout);
	make();
//	for(int i=0;i<=30;i++)
//	{
//		printf("a[%d]=%d\n",i,a[i]);
//	}
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		printf("%d\n",a[n]);
	}
	return 0;
}
