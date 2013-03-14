#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int a[1005][1005],n;

int lowbit(int x)
{
	return x&(-x);
}

int Sum(int x,int y)
{
	int i,j,ans=0;
	for(i=x;i<=n;i+=lowbit(i))
	{
		for(j=y;j<=n;j+=lowbit(j))
			ans^=a[i][j];
	}
	return ans;
}

void Modify(int x1,int y1,int x2,int y2)
{
	int i,j;
	for(i=x1-1;i>0;i-=lowbit(i))
	{
		for(j=y1-1;j>0;j-=lowbit(j))
		{
			a[i][j]^=1;
		}
		for(j=y2;j>0;j-=lowbit(j))
		{
			a[i][j]^=1;
		}
	}
	for(i=x2;i>0;i-=lowbit(i))
	{
		for(j=y1-1;j>0;j-=lowbit(j))
		{
			a[i][j]^=1;
		}
		for(j=y2;j>0;j-=lowbit(j))
		{
			a[i][j]^=1;
		}
	}
}

int main()
{
	int cas,flag=0;
	cin>>cas;
	while(cas--)
	{
		int k;
		if (flag++)
		{
			printf("\n");
		}
		scanf("%d%d",&n,&k);
		memset(a,0,sizeof(a));
		while(k--)
		{
			char c[5];
			scanf("%s",c);
			if(c[0]=='C')
			{
				int x1,x2,y1,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				Modify(x1,y1,x2,y2);
			}
			else
			{
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",Sum(x,y));
			}
		}
	}
	return 0;
}