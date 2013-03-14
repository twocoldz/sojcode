#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,p;
int easy[105],hard[105];
int a[105];

int main()
{
	while(scanf("%d%d",&n,&p)==2)
	{
		memset(easy,0,sizeof(easy));
		memset(hard,0,sizeof(hard));
		int i,j;
		for(i=1;i<=n;i++)
		{
			int max=-1;
			int min=1001;
			for(j=1;j<=p;j++)
			{
				scanf("%d",&a[j]);
				if(a[j]<min)
				{
					min=a[j];
				}
				if(a[j]>max)
				{
					max=a[j];
				}
			}
			for(j=1;j<=p;j++)
			{
				if(a[j]==min)
				{
					easy[j]++;
				}
				if(a[j]==max)
				{
					hard[j]=1;
				}
			}
		}
		int flag = 0;  
        for (i = 1; i<=p; i++)
		{  
            if (easy[i] > n / 2 && hard[i] == 0)
			{  
                if (flag)
				{  
                    printf(" ");  
                }  
                printf("%d",i);  
                flag = 1;  
            }  
        }  
        if (flag == 0)
		{  
            printf("0\n");  
        }  
        else
		{  
            printf("\n");  
        }  
	}
	return 0;
}