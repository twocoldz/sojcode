#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=30005;

int n,m;
int num[maxn],Fath[maxn];

int FindFa(int x)
{
    if(Fath[x]!=x)
    {
        Fath[x]=FindFa(Fath[x]);
    }
    return Fath[x];
}

void Merge(int x,int y)
{
    int i=FindFa(x);
    int j=FindFa(y);
    if(i!=j)
    {
        Fath[j]=i;
        num[i]+=num[j];
    }
}

void Init()
{
    for(int i=0;i<n;i++)
    {
        Fath[i]=i;
        num[i]=1;
    }
}

int main()
{
	int i,j,x,p,q;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		Init();
		for(int i=1;i<=m;i++)
		{
		    int k,x,y;
		    scanf("%d%d",&k,&x);
		    k--;
		    while(k--)
		    {
		        scanf("%d",&y);
		        Merge(x,y);
		    }
		}
		printf("%d\n",num[FindFa(0)]);
	}
	return 0;
}
