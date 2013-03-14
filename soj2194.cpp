#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
	int x,y,pos;
}cow[100005];

int n,maxn;
int a[100005],b[100005];

int lowbit(int k)
{
	return k&(-k);
}

void Modify(int num,int k)
{
	while(num<=maxn)
	{
		a[num]+=k;
		num+=lowbit(num);
	}
}

int Sum(int num)
{
	int ans=0;
	if(num<=0)
		return 0;
	while(num)
	{
		ans+=a[num];
		num-=lowbit(num);
	}
	return ans;
}

bool operator<(const node a,const node b)
{
	if(a.y==b.y)
		return a.x>b.x;
	return a.y<b.y;
} 

int main()
{
	int i;
	while(scanf("%d",&n)&&n)
	{
		maxn=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&cow[i].x,&cow[i].y);
			cow[i].pos=i;
			cow[i].x++;
			cow[i].y++;
			if(cow[i].y>maxn)
			{
				maxn=cow[i].y;
			}
		}

		sort(cow,cow+n);
		memset(a,0,sizeof(a));
		for(i=n-1;i>=0;i--)
		{
			if(i!=n-1&&cow[i].y==cow[i+1].y&&cow[i].x==cow[i+1].x)
			{
				b[cow[i].pos]=b[cow[i+1].pos];
			}
			else
			{
				b[cow[i].pos]=Sum(cow[i].x);
			}
			Modify(cow[i].x,1);
		}
		for(i=0;i<n;i++)
		{
			if(i)
				printf(" ");
			printf("%d",b[i]);
		}
		printf("\n");
	}
	return 0;
}