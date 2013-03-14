#include <iostream>
#include <cstdio>
#include <cstring>
#define Pi 3.141592653589793
using namespace std;

double size[10005];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n,f;
		double left=0,right;
		double middle;
		memset(size,0,sizeof(size));
        cin>>n>>f;
        f++;
        for(i=1;i<=n;i++)
        {
            scanf("%lf",&size[i]);
			size[i]*=size[i]*Pi;
			if(size[i]>right)
			{
				right=size[i];
			}
        }
        if(n==1)
        {
            printf("%.6lf\n",size[1]/f);
			continue;
        }
		while((right-left)>=10e-8||(left-right)>=10e-8)
		{
			middle=(left+right)/2;
			int temp=f;
			for(i=1;i<=n&&temp>0;i++)
			{
				temp-=(int)(size[i]/middle);
			}
			if(temp>0)
			{
				right=middle;
			}
			else
			{
				left=middle;
			}
		}
		printf("%.6lf\n",right);
    }
    return 0;
}