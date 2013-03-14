#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		priority_queue<int> q;
		int sum=n+m;
		int x;
		while(sum--)
		{
			scanf("%d",&x);
			if(x!=-1)
			{
				q.push(x);
			}
			else
			{
				int ans=q.top();
				q.pop();
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}