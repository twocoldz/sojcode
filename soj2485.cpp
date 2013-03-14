#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool cow[10][10],col[10][10],sqr[10][10];

int num[10][10];

void make()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			cow[i][j]=false;
			col[i][j]=false;
			sqr[i][j]=false;
		}
	}
}

bool dfs(int x,int y)
{
	if(x==10)
		return true;
	bool flag=false;
	if(num[x][y])
	{
		if(y==9)
			flag=dfs(x+1,1);
		else
			flag=dfs(x,y+1);
		if(flag)
			return true;
		else
			return false;
	}
	else
	{
		int k=3*((x-1)/3)+(y-1)/3+1;
		for(int i=1;i<=9;i++)
		{
			if(!cow[x][i]&&!col[y][i]&&!sqr[k][i])
			{
				num[x][y]=i;
				cow[x][i]=true;
				col[y][i]=true;
				sqr[k][i]=true;
				if(y==9)
					flag=dfs(x+1,1);
				else
					flag=dfs(x,y+1);
				if(!flag)
				{
					num[x][y]=0;
					cow[x][i]=false;
					col[y][i]=false;
					sqr[k][i]=false;
				}
				else
					return true;
			}
		}
	}
	return false;
}

int main()
{
	int cas=1;
	while(true)
	{
		int i,j;
		scanf("%d",&num[1][1]);
		if(num[1][1]==-1)
		{
			break;
		}
		make();
		for(i=2;i<=9;i++)
		{
			scanf("%d",&num[1][i]);
		}
		for(i=2;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				scanf("%d",&num[i][j]);
			}
		}
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				if(num[i][j])
				{
					cow[i][num[i][j]]=true;
					col[j][num[i][j]]=true;
					int k=3*((i-1)/3)+(j-1)/3+1;
					sqr[k][num[i][j]]=true;
				}
			}
		}
		dfs(1,1);
		if(cas!=1)
			printf("\n");
		printf("Case %d:\n",cas);
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				if(j!=9)
					printf("%d ",num[i][j]);
				else
					printf("%d",num[i][j]);
			}
			printf("\n");
		}
		cas++;
	}
	return 0;
}