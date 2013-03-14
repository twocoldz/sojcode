#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    string n,m;
    while(cin>>m>>n)
    {
        if(m=="0"&&n=="0")
        {
            break;
        }
        if(m==n)
        {
            printf("well done!\n");
            continue;
        }
        int lenm=m.length();
        int lenn=n.length();
        int i,j;
        if(lenn>lenm)
        {
            printf("are you crazy?\n");
            continue;
        }
        int temp=0;
        int*c=new int[lenm+1];
        for(i=lenm-1,j=lenn-1;i>=0;i--,j--)
        {
            if(j>=0)
            {
                if((m[i]-'0')>=(n[j]-'0')+temp)
                {
                    c[i]=(int)(m[i]-'0')-(int)(n[j]-'0')-temp;
                    temp=0;
                }
                else
                {
                    c[i]=10+(int)(m[i]-'0')-(int)(n[j]-'0')-temp;
                    temp=1;
                }
            }
            else
            {
                if((int)(m[i]-'0')>=temp)
                {
                    c[i]=(int)(m[i]-'0')-temp;
                    temp=0;
                }
                else
                {
                    c[i]=10+(int)(m[i]-'0')-temp;
                    temp=1;
                }
            }

        }
        i=0;
        while(!c[i++]);
        for(i--;i<lenm;i++)
        {
            printf("%d",c[i]);
        }
        printf("\n");
    }
}
