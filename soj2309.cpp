#include <iostream>
#include <cstring>
using namespace std;

int k,n;
long long c[10005];

int lowbit(int x)
{
	return x&(-x);
}

void Insert(int pos)
{
	while(pos<=n)
	{
		c[pos]+=1;
		pos+=lowbit(pos);
	}
}

int Sum(int x)
{
	int s=0;
	while(x>0)
	{
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}

int main()
{
	while(scanf("%d%d",&n,&k)!=EOF&&n)
	{
		int i,j,r,pos;
		long long temp,ans=0;
		for(i=1;i<=k;i++)
		{
			memset(c,0,sizeof(c));
			for(j=1,temp=0;j<=n;j++)
			{
				scanf("%d",&r);
				temp+=j-Sum(r)-1;
				Insert(r);
			}
			if(temp>ans)
			{
				ans=temp;
				pos=i;
			}
		}
		cout<<pos<<endl;
	}
	return 0;
}