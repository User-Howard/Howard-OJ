#include<iostream>
using namespace std;


int main(void)
{
	int a,b;
	while(scanf("%d%d",&a,&b) != EOF)
	{
		if(b==0)
			printf("Go Kevin!!\n");
		else
		{
			for(int i=1;a>0;a-=i,i+=b);
			printf("%s\n",a==0?"Go Kevin!!" :"No Stop!!");
		}
	}
	return 0;
}
