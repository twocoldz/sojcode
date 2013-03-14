#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Preson
{
	char name[100];
	int pingjia[22];
}preson[22];

void inti()
{
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=20;j++)
		{
			preson[i].pingjia[j]=0;
		}
	}
}

char GetChar()
{
	char c;
	while((c=getchar())&&(c==' '||c=='\n'));
	return c;
}

int main()
{
	int n;
	int cases=1;
	while(scanf("%d",&n)==1&&n)
	{
		inti();
		if(cases!=1)
			printf("\n");
		printf("Group %d\n",cases++);
		int i,j,k;
		int sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s",preson[i].name);
			char temp;
			for(j=(i-1)==0?n:(i-1)%n,k=1;k<n;k++,j=(--j)==0?n:j%n)
			{
				temp=GetChar();
				if(temp=='N')
				{
					preson[i].pingjia[j]=1;
					sum++;
				}
			}
		}
		if(sum==0)
		{
			printf("Nobody was nasty\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			for(j=(i-1)==0?n:(i-1)%n,k=1;k<n;k++,j=(--j)==0?n:j%n)
			{
				if(preson[i].pingjia[j]==1)
				{
					printf("%s was nasty about %s\n",preson[j].name,preson[i].name);
				}
			}
		}
		
	}
	return 0;
}