#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

double c[10][10];    //c[i][j]��ʾ��iλ���Ӹߵ��ͣ��ڵ�j��ȡ����ȷȡֵ�ĸ���
double dp[10][1<<8];  //dp[i][j]��ʾ�ڵ�i�֣�ȡ����ȷ��״̬Ϊj������ĸ��� �������Ľ����sum{dp[1--n][1<<n-1]}
char s[11];
int len[10];
int n;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            len[i]=strlen(s);
            maxlen=max(maxlen,len[i]);
        }

        for(int i=0;i<=n;i++)
        {
            int j;
            for(j=1;j<=len[i];j++)
            {
                c[i][j]=1.0/(double)(len[i]-j+1);
                //printf("c[%d][%d]=%.3lf\n",i,j,c[i][j]);
            }
            for(;j<=maxlen;j++)
            {
                c[i][j]=0.0;
            }
        }

        for(int i=1;i<(1<<n);i++)
        {
            dp[1][i]=1.0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                    dp[1][i]*=c[j][1];
                else
                    dp[1][i]*=(1-c[j][1]);
            }
        }
        double ans=dp[1][(1<<n)-1];
        //printf("%.3lf\n",ans);
        double tmp;
        bool f;
        for(int i=2;i<=maxlen;i++)
        {
            for(int j=1;j<(1<<n);j++)              //���֮ǰ��״̬DP��̫һ�� ���Ǵ�J״̬��Ϊ����״̬ �����Ƿ�����
            {
                dp[i][j]=0.0;
                for(int k=1;k<(1<<n)-1;k++)
                {
                    if(((j&k)==k)&&(j^k)>0)
                    {
                        //��k״̬��j״̬���ܲ�������Ҫ����һλ���ԣ�����Ҫһ��ѭ��
                        f=false;
                        tmp=dp[i-1][k];
                        for(int l=0;l<n;l++)
                        {
                            if(((1<<l)&k)==0)
                            {
                                if((1<<l)&j)
                                    tmp*=c[l][i];
                                else
                                    tmp*=(1-c[l][i]);
                                //printf("i=%d j=%d\n",i,j);
                            }
                            else
                            {
                                f|=(len[l]>=i-1);           //ֻҪj״̬��k״̬���������һλ��ȡ��i�λ��п���ȡ���ģ�����Ҫ�����������
                            }
                        }
                        if(f)
                        {
                            dp[i][j]+=tmp;
                        }
                    }
                }
            }
            ans+=dp[i][(1<<n)-1];
        }
        printf("%0.3lf\n",ans);
    }
    return 0;
}
