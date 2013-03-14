#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
char a[205],b[205];
int dp[205][205];

int main()
{
    while(scanf("%s%s",a,b)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        int lena=strlen(a);
        int lenb=strlen(b);
        for(int i=1;i<=lena;i++)
        {
            for(int j=1;j<=lenb;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        printf("%d\n",dp[lena][lenb]);
    }
    return 0;
}
