#include <iostream>
#include <map>
#include <cstdio>
#include <string>
using namespace std;

string str;
int scores;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
	    int m;
		int sum=0;
		map<string,int> mapstudent;
		map<string,int>::iterator iter;
		cin>>m;
		while(m--)
		{
			cin>>str>>scores;
			iter=mapstudent.find(str);
			if(iter!=mapstudent.end())
			{
				if((iter->second)<scores)
				{
					iter->second=scores;
					sum++;
				}
			}
			else
			{
				mapstudent.insert(pair<string,int>(str,scores));
			}
		}
		cout<<sum<<endl;

	}
	return 0;
}
