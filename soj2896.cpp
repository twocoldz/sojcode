#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char c[50005];
int data[50005];
int sum[50005];

int main()
{
	while(scanf("%s",c)!=-1)
	{
		memset(data,0,sizeof(data));
		memset(sum,0,sizeof(sum));
		if(c[0]=='0')
			break;
		int len=strlen(c);
		int i;
		for(i=0;i<len;i++)
		{
			data[i]=c[i]-'0';
		}
		sum[0]=1;
		int temp=data[0]*10+data[1];
		if(temp>=10&&temp<=26&&data[1])
			sum[1]=2;
		else
			sum[1]=1;
		for(i=2;i<len;i++)
		{
			temp=data[i-1]*10+data[i];
			if(data[i]==0)
				sum[i]=sum[i-2];
			else if(data[i]&&temp>=10&&temp<=26)
				sum[i]=sum[i-1]+sum[i-2];
			else
				sum[i]=sum[i-1];
		}
		printf("%d\n",sum[len-1]);

	}
	return 0;
}