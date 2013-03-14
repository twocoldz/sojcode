#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int wall[205][205];
int len,wide,k;

int Cal()
{
	int ans=0;
	for(int i=0;i<=len;i++)
	{
		int temp=0;
		for(int j=0;j<=wide;j++)
		{
			if(wall[j][i]!=0)
				temp++;
		}
		while(temp>k)
		{
			int r=-1,maxcount=0;
			for(int j=0;j<=wide;j++)
			{
				if(wall[j][i]!=0)
				{
					int cc=i+1,count=0;
					while(wall[j][cc++]==wall[j][i])
						count++;
					if(count>maxcount)
					{
						maxcount=count;
						r=j;
					}
				}
			}
			for(int cc=i;cc<=i+maxcount;cc++)
				wall[r][cc]=0;
			temp--;
			++ans;
		}
	}
	return ans;
}

int main()
{
	int cas;
	cin>>cas;
	while(cas--)
	{
		int n;
		len=0,wide=0;
		int leftx,lefty,rightx,righty;
		memset(wall,0,sizeof(wall));
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d %d",&leftx,&lefty,&rightx,&righty);
			if(leftx>rightx)
				swap(leftx,rightx);
			if(rightx>len)
				len=rightx;
			if(righty>wide)
				wide=righty;
			for(int j=leftx;j<=rightx;j++)
			{
				wall[righty][j]=i;
			}
		}
		printf("%d\n",Cal());
	}
	return 0;
}