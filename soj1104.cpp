#include <cstdio>
#include <algorithm>

int main()
{
    int n;
    scanf("%d",&n);//==1&&n)
    {
        int a,b,sum;
        int cnt_9=0;
        int last=0;
        scanf("%d%d",&a,&b);
        last=a+b;
        n--;
        while(n--)
        {
            scanf("%d%d",&a,&b);
            sum=a+b;
            if(sum>9)
            {
                printf("%d",last+1);
                for(int i=0;i<cnt_9;i++)
                    printf("0");
                cnt_9=0;
                last=sum%10;
            }
            else if(sum<9)
            {
                printf("%d",last);
                for(int i=0;i<cnt_9;i++)
                    printf("9");
                cnt_9=0;
                last=sum;
            }
            else
                cnt_9++;
        }
        if(sum!=9)
            printf("%d",last);
        else
        {
            printf("%d",last);
            for(int i=0;i<cnt_9;i++)
                printf("9");
        }
        printf("\n");
    }
    return 0;
}
