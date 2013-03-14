#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int lx[105],ly[105],rx[105],ry[105];

int main()
{
    int n;
    int cases=1;
    while(scanf("%d",&n)==1&&n)
    {
        printf("Desktop %d:\n",cases++);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",lx+i,ly+i,ry+i,rx+i);
            rx[i]+=lx[i];
            ry[i]+=ly[i];
        }
        int m,x,y;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            int i;
            for(i=n;i>=1;i--)
            {
                if(x>=lx[i]&&y>=ly[i]&&x<rx[i]&&y<ry[i])
                    break;
            }
            if(i==0)
                printf("background\n");
            else
                printf("window %d\n",i);
        }
    }
}
