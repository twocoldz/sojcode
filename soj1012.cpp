#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	int n;
	bool a[1000001];
	memset(a,false,sizeof(a));
	while(cin>>n&&n!=0)
	{
		int k,com,sum=0;
		double temp;
		for(int i=3;2*i*i<=n*n;i++)
		{
			for(int j=i+1;i*i+j*j<=n*n;j++)
			{
				temp=sqrt(i*i+j*j);
				com=temp;
				if(temp-com<=10e-6)
				{
					a[i]=a[j]=a[com]=true;
					if(gcd(i,j)==1)
					{
						sum++;
					}
				}
				
			}
		}
		for(com=0,k=1;k<=n;k++)
		{
			if(!a[k])
			{
				com++;
			}
		}
		cout<<sum<<" "<<com<<endl;
	
	}	
	return 0;
}
