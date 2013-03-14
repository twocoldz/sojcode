#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    int pos,p;
    double v;
}ans[3];

inline void Init()
{
    ans[0].v=ans[1].v=ans[2].v=0;
}

void Updata(int a,int b)
{
    ans[b].p=ans[a].p;
    ans[b].v=ans[a].v;
    ans[b].pos=ans[a].pos;
}

int main()
{
    double a,b;
    int n;
    while(scanf("%d",&n)==1)
    {
        Init();
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&a,&b);
            double v=a/b;
            if(v>ans[0].v)
            {
                Updata(1,2);
                Updata(0,1);
                ans[0].v=v;
                ans[0].pos=i;
                ans[0].p=b;
            }
            else if(v>ans[1].v)
            {
                Updata(1,2);
                ans[1].v=v;
                ans[1].pos=i;
                ans[1].p=b;
            }
            else if(v>ans[2].v)
            {
                ans[2].v=v;
                ans[2].pos=i;
                ans[2].p=b;
            }
        }
        int sum;
        sum=ans[0].p+ans[1].p+ans[2].p;
        printf("%d\n",sum);
        printf("%d\n%d\n%d\n",ans[0].pos,ans[1].pos,ans[2].pos);
    }
    return 0;
}
