#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int num;
		cin>>num;
		cout<<num-(num-1)/5<<endl;
	}
}