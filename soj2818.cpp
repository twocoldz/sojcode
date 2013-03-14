#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char s[1000005];
int w[4][4]={0,1,2,2,1,0,1,1,2,1,0,2,2,1,2,0};

int main()
{
    while(scanf("%s",s)==1)
    {
        int i,j,a=2,b=3,t;
        int count=0;
        int len=strlen(s);
        for(i=0;i<len;i++)
        {
            t=s[i]-'0';
            if(w[a][t]<w[b][t])
            {
                count+=w[a][t];
                a=t;
            }
            else if(w[a][t]>w[b][t])
            {
                count+=w[b][t];
                b=t;
            } 
            else
            {
                for(j=i+1;j<len;j++)
                {
                    if(s[j]-'0'==a||s[j]-'0'==b)
                        break;
                }
                if(s[j]-'0'==a)
                {
                    count+=w[b][t];
                    b=t;
                }
                else
                {
                    count+=w[a][t];
                    a=t;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}