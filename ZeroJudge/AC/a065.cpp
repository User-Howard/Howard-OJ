#include<iostream>
#include<math.h>
using namespace std;


int main(void)
{
	string a;
	while(cin>>a)
	{
		for(int i=0;i<=a.size()-2;i++)
		{
			cout<<abs((int)a[i+1]-(int)a[i]);
		}
		cout<<endl;
	}
	return 0;
}
