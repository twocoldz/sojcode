#include <iostream>
#include <map>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	int n;
	string str;
	int scores;
	while(scanf("%d",&n)==1&&n)
	{
		int sum=0;
		map<string,int> mapstudent;
		map<string,int>::iterator iter;
		while(n--)
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