#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node
{
    char g[5];
    int a,b;
}e[105];

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            scanf("%s %d %d",e[i].g,&e[i].a,&e[i].b);
        int A,B,f=0;
        char t[5];
        bool v[5],u[5];
        for(int i=1000;f==0&&i<=9999;i++)
        {
            int ii=i;
            for(int j=3;j>=0;j--)
            {
                t[j]=ii%10+'0';
                ii/=10;
            }
            t[4]='\0';
            int j;
            for(j=0;f==0&&j<n;j++)
            {
                A=0,B=0;
                memset(v,0,sizeof(v));
                memset(u,0,sizeof(u));
                for(int k=0;k<4;k++)
                {
                    if(t[k]==e[j].g[k])
                    {
                        A++;
                        v[k]=u[k]=1;
                    }
                }
                if(A!=e[j].a)
                    break;
                else
                {
                    for(int k=0;k<4;k++)
                    {
                        if(!v[k])
                        {
                            for(int l=0;l<4;l++)
                            {
                                if(!u[l]&&t[k]==e[j].g[l])
                                {
                                    B++;
                                    v[k]=1;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(B!=e[j].b)
                {
                    break;
                }
            }
            if(j==n)
                f=1;
        }
        if(f)
        {
            printf("%s\n",t);
        }
        else
            printf("NONE\n");
    }
    return 0;
}
