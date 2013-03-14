#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node
{
	int a,b;
}pro[100005];

bool cmp(node x,node y)
{
	return (x.a-x.b)>(y.a-y.b);
}

int main()
{
	int cas;
	cin>>cas;
	while(cas--)
	{
		int i,n,m,flag=1;
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&pro[i].a,&pro[i].b);
		}
		sort(pro+1,pro+n+1,cmp);
		for(i=1;i<=n;i++)
		{
			if(pro[i].a>m)
			{
				flag=0;
				break;
			}
			m-=pro[i].b;
		}
		if(flag)
		{
			printf("Clever Dahema\n");
		}
		else
		{
			printf("Stupid Dahema\n");
		}	
	}
	return 0;
}