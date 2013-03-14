#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dif[5005];
int n,k;

struct node
{
	int fir;
	int pos;
}group[5005];

bool cmp(node a,node b)
{
	if(a.fir==b.fir)
		return dif[a.pos]<dif[b.pos];
	return a.fir<b.fir;
}

int GetSmall(int x,int y)
{
	if(group[x].fir==group[y].fir)
	{
		if(dif[group[x].pos]<dif[group[y].pos])
			return x;
		else
			return y;
	}
	else
	{
		if (group[x].fir<group[y].fir)
		{
			return x;
		}
		else
			return y;
	}
}

void Modify()
{
	int root=1;
	while(true)
	{
		int left=root*2;
		int right=root*2+1;
		int minx=left>n?root:GetSmall(left,root);
		int miny=right>n?minx:GetSmall(minx,right);
		if(miny==root)
			break;
		else if(miny==left)
		{
			int temp=group[root].fir;
			group[root].fir=group[left].fir;
			group[left].fir=temp;
			root=left;
		}
		else
		{
			int temp=group[root].fir;
			group[root].fir=group[right].fir;
			group[right].fir=temp;
			root=right;
		}
	}
}

int main()
{
	while(scanf("%d%d",&n,&k)==2)
	{
		int i,total=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&group[i].fir);
			group[i].pos=i;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&dif[i]);
		}
		sort(group+1,group+1+n,cmp);
		while(k--)
		{
			Modify();
			total+=group[1].fir;
			group[1].fir+=dif[group[1].pos];

		}
		printf("%d\n",total);
	}
	return 0;
}