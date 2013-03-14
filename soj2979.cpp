#include <iostream>
#include <cstdio>
using namespace std;

int n,k,relation;
int fa[50005],r[50005];

void make()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		r[i]=0;
	}
}

int find(int x)
{
	if(x==fa[x])
		return fa[x];
	int temp=fa[x];
	fa[x]=find(fa[x]);
	r[x]=(r[x]+r[temp])%3;
	return fa[x];
}

void Union(int x,int y,int tx,int ty)
{
	fa[ty]=tx;
	r[ty]=(r[x]-r[y]+2+relation)%3;
}

int main()
{
	while(scanf("%d%d",&n,&k)!=EOF&&n)
	{
		int tx,ty,a,b,count=0;
		make();
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d%d",&relation,&a,&b);
			if(a>n||b>n||(relation==2&&a==b))
			{
				count++;
				continue;
			}
			tx=find(a);
			ty=find(b);
			if(tx!=ty)
			{
				Union(a,b,tx,ty);
			}
			else
			{
				if(relation==1&&r[a]!=r[b])
				{
					count++;
					continue;
				}
				else if(relation==2&&( r[a]!=( (r[b]+2)%3 ) ))
				{
					count++;
					continue;
				}
			}
			
		}
		printf("%d\n",count);
	}
	return 0;
}
