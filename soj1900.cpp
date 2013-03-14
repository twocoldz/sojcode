#include <cstdio>
#include <cstring>

int c[8]={1,2,4,8,16,32,64,128};

int Rev(char a[],int b,int e)
{
    int ans=0;
    for(int i=e;i>=b;i--)
    {
        if(a[i]=='1')
            ans+=c[e-i];
    }
    return ans;
}

int main()
{
    int n;
    char str[35];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",str);
        int a=Rev(str,0,7);
        int b=Rev(str,8,15);
        int c=Rev(str,16,23);
        int d=Rev(str,24,31);
        printf("%d.%d.%d.%d\n",a,b,c,d);
    }
    return 0;
}
