#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int len[64],Min,sum,n;
bool used[64];

int dfs(int k,int rest,int total)
{
	int i;
	if(total==Min)
		return 1;
	for(i=k;i<n;i++)
	{
		if(!used[i]&&len[i]<=rest)
		{
			used[i]=1;
			if(len[i]==rest)
			{
				if(dfs(1,Min,total-len[i]))
					return 1;
			}
			else if(dfs(i+1,rest-len[i],total-len[i]))
				return 1;
			used[i]=0;
			if (len[i]==rest)
			{
				return 0;
			}
			if(total==sum)
			{
				return 0;
			}
			if(rest==Min)
			{
				return 0;
			}
			while(len[i+1]==len[i])
				i++;
		}
	}
	return 0;
}

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	while(scanf("%d",&n)!=EOF&&n)
	{
		sum=0;
		memset(used,false,sizeof(used));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&len[i]);
			sum+=len[i];
		}
		sort(len,len+n,cmp);
		Min=len[0];
		while(sum%Min!=0)
			Min++;
		while(dfs(1,Min,sum)==0)
		{
			Min++;
			while(sum%Min!=0)
				Min++;
		}
		printf("%d\n",Min);
	}
	return 0;
}