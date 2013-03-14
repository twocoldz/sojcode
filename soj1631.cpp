#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char str[105];
	int i=0;
	while((str[i++]=getchar())!=EOF&&str[i-1]!=' ')
	{
		;
	}
	for (i-=2;i>=0;i--) 
	{
		printf("%c",str[i]);
	}
	printf("\n");
	return 0;
}