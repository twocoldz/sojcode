#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int fa[80005];
int cow[80005];

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        char c[2];
        int k;
        fa[0]=-1;
        cow[0]=-1;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",c);
            if(c[0]=='a')
            {
                scanf("%d",&k);
                printf("%d\n",k);
                fa[i]=i-1;
                cow[i]=k;
            }
            else if(c[0]=='s')
            {
                fa[i]=fa[fa[i-1]];
                cow[i]=cow[fa[i-1]];
                printf("%d\n",cow[i]);
            }
            else
            {
                scanf("%d",&k);
                fa[i]=fa[k-1];
                cow[i]=cow[k-1];
                printf("%d\n",cow[i]);
            }
            //printf("fa[i]=%d cow[i]=%d\n",fa[i],cow[i]);
        }
    }
    return 0;
}
