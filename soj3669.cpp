#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
char in[100005],out[200005];
int a[3]={1,16,256};

int main()
{
    while(scanf("%s",in)!=EOF)
    {
        if(in[0]=='0')
        {
            printf("0\n");
            continue;
        }
        int len=strlen(in);
        int t=0,k=0;
        for(int i=len-1;i>=0;)
        {
            for(int j=0;j<3&&i>=0;j++,i--)
            {
                if(in[i]>='0'&&in[i]<='9')
                    t+=a[j]*(in[i]-'0');
                else
                    t+=a[j]*(in[i]-'A'+10);
            }
            for(int j=0;j<4;j++,k++)
            {
                out[k]=t%8+'0';
                t/=8;
            }
        }
        while(out[k-1]=='0')
            k--;
        for(int i=k-1;i>=0;i--)
            printf("%c",out[i]);
        printf("\n");
    }
    return 0;
}
