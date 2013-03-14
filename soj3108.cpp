#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

#define min(a,b,c) (a<(b<c?b:c)?a:(b<c?b:c))

int dp[2001][2001];
int lena,lenb;
string a,b;

void Dp()
{
	int i,j,cost;
	for(i=0;i<=lena;i++)
		dp[i][0]=i;
	for(j=0;j<=lenb;j++)
		dp[0][j]=j;
	for(i=1;i<=lena;i++)
	{
		for(j=1;j<=lenb;j++)
		{
			if(a[i-1]==b[j-1])
                cost=0;
            else
                cost=1;
            dp[i][j]=min(dp[i-1][j-1]+cost,dp[i-1][j]+1,dp[i][j-1]+1);
		}
	}
}

int main()
{
	while(cin>>a>>b)
	{
		lena=a.size(),lenb=b.size();
		Dp();
		cout<<dp[lena][lenb]<<endl;
	}
	return 0;
}