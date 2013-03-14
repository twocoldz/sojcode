#include <stdio.h>
#include <string.h>
#include <math.h>

int dif[3005];

int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		memset(dif,0,sizeof(dif));
		int cur,pre,i;
		scanf("%d",&pre);
		for( i=1;i<n;i++)
		{
			scanf("%d",&cur);
			int temp=abs(cur-pre);
			dif[temp]=1;
			pre=cur;
		}
		for( i=1;i<n;i++)
		{
			if(!dif[i])
			{
				break;
			}
		}
		if(i==n)
		{
			printf("Jolly\n");
		}
		else
		{
			printf("Not jolly\n");
		}
	}
	return 0;
}