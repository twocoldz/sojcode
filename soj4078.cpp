#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

int sum;
int a[1025];

int Cn2(int x)
{
	return x*(x-1)/2;
}

int main()
{
	int i,j,n;
	long long ans;
	string t;
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(a,0,sizeof(a));
		ans=0;
		for(i=0;i<n;i++)
		{
			sum=0;
			cin>>t;
			j=0;
			while(t[j]!='\0')
			{
				sum|=1<<(int)(t[j]-'0');
				j++;
			}
			a[sum]++;
		}
		for(i=1;i<=1024;i++)
		{
			ans+=Cn2(a[i]);
			for(j=i+1;j<=1024;j++)
			{
				if(i&j)
				{
					ans+=a[i]*a[j];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}