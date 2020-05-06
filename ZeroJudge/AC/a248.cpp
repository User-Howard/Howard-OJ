#include<iostream>
using namespace std;


int main(void)
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		cout<<a/b<<".";
		a=(a%b)*10;
		
		for(int i=0;i<c;i++)
		{
			cout<<a/b;
			a=(a%b)*10;
		}
		cout<<endl;
	}
	return 0;
}
