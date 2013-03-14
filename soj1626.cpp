#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool vis[22];
int stick[22];
bool flag;
int sum,n;

bool cmp(int a,int b)
{
	return a>b;
}

void Dfs(int m,int k,int num)
{
	int i;
	if(num==3)
	{
		flag=false;
		return ;
	}
	if(flag)
	{
		if(k==0)
			Dfs(1,sum,num+1);
		else
		{
			for(i=m;i<=n;i++)
			{
				if(vis[i]==0&&stick[i]<=k)
				{
					vis[i]=true;
					Dfs(i+1,k-stick[i],num);
					vis[i]=false;
				}
			}
		}
	}
}

int main()
{
	int cas;
	cin>>cas;
	while(cas--)
	{
		int i,num;
		cin>>n;
		for(i=1,sum=0;i<=n;i++)
		{
			scanf("%d",&stick[i]);
				sum+=stick[i];
		}
		if(sum%4!=0)
		{
			printf("no\n");
			continue;
		}
		sum/=4;
		sort(stick+1,stick+1+n,cmp);
		if(sum<stick[1])
		{
			printf("no\n");
			continue;
		}
		num=0;
		flag=true;
		memset(vis,false,sizeof(vis));
		Dfs(1,sum,num);
		if(flag)
		{
			printf("no\n");
			continue;
		}
		else
		{
			printf("yes\n");
			continue;
		}
	}
	return 0;
}