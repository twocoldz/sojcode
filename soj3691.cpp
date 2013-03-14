#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int f[16];
char a[16][16];

int main()
{
    while(scanf("%s",a[0]))
    {
        if(a[0][0]=='E')
            break;
        for(int i=1;i<15;i++)
            scanf("%s",a[i]);
        int ans=20;
        int res;
        for(int i=0;i<(1<<15);i++)
        {
            res=0;
            for(int j=0;j<15;j++)
            {
                if(i&(1<<j))
                    f[j]=1,res++;
                else
                    f[j]=0;
            }
            if(res>=ans)
                continue;
            int t=0;
            for(int j=0;j<15;j++)
            {
                int flag=0;
                for(int k=0;k<15;k++)
                {
                    if(f[k])
                        continue;
                    if(a[j][k]=='#')
                        flag=1;
                }
                if(flag==1)
                    t++;
                if(t>res)
                    break;
            }
            if(t<=res)
                ans=min(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}
