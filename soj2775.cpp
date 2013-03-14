#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;
const int N = 1005;
long long x[N],d[N][N];
int s[N][N];

int main()
{
    int l,n;
	while(scanf("%d%d", &l,&n)==2)
	{
		for (int i = 1; i <= n; ++i)
            scanf("%lld",x+i);
        x[0]=0;
		x[++n]=l;
		for (int i = 0; i < n; ++i)
		{
            d[i][i+1] = 0;
            s[i][i+1] = i;
		}
		for (int i = n - 2; i >=0; --i)
		{
            for (int j = i + 2; j <= n; ++j)
            {
                int Min= inf, p;
                int st = max(s[i][j-1], i + 1), dt = min(s[i + 1][j], j - 1);
                for (int k = st; k <= dt; ++k)
                {
                    int t = d[i][k] + d[k][j];
                    if (t <Min)
                    {
                        Min= t;
                        p = k;
                    }
                }
                d[i][j] = Min + x[j] - x[i];
                s[i][j] = p;
            }
		}
		printf("%lld\n", d[0][n]);
	}
	return 0;
}
