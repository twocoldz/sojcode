#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
long long B,D;
int w[700005];

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        char c[12];
        for(int i=1;i<=n;i++)
        {
            scanf("%s",c);
            w[i]=0;
            for(int j=0;c[j];j++)
            {
                w[i]=w[i]*10+c[j]-'0';
            }
        }
        B=D=0;
        for(int i=n;i>=1;i--)
        {
            if(D+w[i]>=B)
            {
                long long t=B;
                B=D+w[i];
                D=t;
            }
        }
        printf("%lld %lld\n",B,D);
    }
    return 0;
}
