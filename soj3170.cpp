#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;



int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x1,x2,x3,x4,y1,y2,y3,y4;
		int flag;
		scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		if(x1<=x3)
		{
			if(x2>x3)
			{
				if(y1<=y3)
				{
					if(y2>y3)
					{
						flag=1;
					}
					else
					{
						flag=0;
					}
				}
				else if(y1>=y3)
				{
					if(y4>y1)
					{
						flag=1;
					}
					else
						flag=0;
				}
				else
					flag=0;
			}
			else
				flag=0;
		}
		if(flag&&x1>=x3)
		{
			if(x4>x2)
			{
				if(y1>=y3)
				{
					if(y4>y1)
					{
						flag=1;
					}
					else
						flag=0;
				}
				else if(y3>=y1)
				{
					if(y2>y3)
					{
						flag=1;
					}
					else
						flag=0;
				}
				else
					flag=0;
			}
			else
			{
				flag=0;
			}
		}
		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}