#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n)
	{
		int i,m,sum,avg,cishu;
		int*p;
		cin>>m;
		p=new int[m];
		for(i=0,sum=0;i<m;i++)
		{
			cin>>p[i];
			sum+=p[i];
		}
		avg=sum/m;
		for(i=0,cishu=0;i<m;i++)
		{
			if(p[i]!=avg)
			{
				cishu++;
				p[i+1]-=(avg-p[i]);
			}
		}
		cout<<cishu<<endl;
		n--;
	}
	return 0;
}