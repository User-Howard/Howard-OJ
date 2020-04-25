#include<iostream>
using namespace std;


int main()
{

	int M,D,S;
	while(cin>>M>>D)
	{
		S=(M*2+D)%3;
		if(S==0)
			printf("普通");
		
		else if(S==1)
			printf("吉");
		
		else if(S==2)
			printf("大吉");
		
	}
	return 0;
}
