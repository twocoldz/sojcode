#include <stdio.h>
#include <math.h>
int x1,x2,x3,y10,y2,y3;

/*inline bool Judge()
{
    int t1=x2-x1,t2=y2-y10,t3=x2-x3,t4=y2-y3;
    if(t1*t3==t2*t4)
    {
        return false;
    }
    else
    {
        return true;
    }
}

inline double Cal()
{
    double l1=sqrt((x2-x1)*(x2-x1)+(y2-y10)*(y2-y10));
    double l2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    double l3=sqrt((x1-x3)*(x1-x3)+(y10-y3)*(y10-y3));
    double t=(l1+l2+l3)/2;
    double ans=sqrt(t*(t-l1)*(t-l2)*(t-l3));
    return ans*2;
}*/

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d",&x1,&y10,&x2,&y2,&x3,&y3);
        int ans=abs(x1*y2+x2*y3+x3*y10-x1*y3-x2*y10-x3*y2);
        float sum=ans;
        if(ans!=0)
        {
            printf("%.1f\n",sum);
        }
        else
        {
            printf("Error\n");
        }
    }
    return 0;
}
