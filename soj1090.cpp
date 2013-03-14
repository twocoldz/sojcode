
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int s,p,y,jane;
		int Sage,Yage,Page;
		scanf("%d%d%d%d",&s,&p,&y,&jane);
		for(Yage=0,Page=Yage+p,Sage=Yage+y;(Yage+Page+Sage)<(12+jane);Yage++,Page++,Sage++)
			;
		if(s+p==y)
		{
			if(Yage+Page+Sage-12-jane==2)
				Yage--,Page--;
			else if(Yage+Page+Sage-12-jane==1)
				Yage--;
			else
				;
		}
		else
		{
			if(Yage+Page+Sage-12-jane==2)
				Sage--,Yage--;
			else if(Yage+Page+Sage-12-jane==1)
				Yage--;
			else
				;
		}
		printf("%d %d %d\n",Sage,Page,Yage);
	}
	return 0;	
}
