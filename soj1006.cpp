#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char line[100];
	char temp[11];
	int len;
	while((cin>>temp)&&strcmp(temp,"ENDOFINPUT")!=0)
	{
			getchar();
			gets(line);
			len=sizeof(line);
			for(int i=0;i<len;i++)
			{
				if(line[i]>='F'&&line[i]<='Z')
				{
					line[i]-=5;
				}
				else if(line[i]>='A'&&line[i]<='E')
				{
					line[i]=line[i]-'A'+'Z'-4;
				}
			}
			gets(temp);
			if(strcmp(temp,"END")==0)
			{
				cout<<line<<' '<<endl;
			}
	}
	return 0;
}