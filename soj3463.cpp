#include<stdio.h>
char str[100000]={0};
int main()
{
	int a,i,t;
	while(scanf("%d",&a)!=EOF)
	{
		i=0;
		t=0;
		getchar();
		gets(str);
				while(1)
				{
					if(str[t]=='1'&&str[t+1]==' ')
					{
						i++;
						t +=2;
					}
					else {break;}
				}

				if(i%2==0)
					printf("Alice\n");
				else
					printf("Bob\n");
	}

}
