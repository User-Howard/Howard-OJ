#include<iostream>
using namespace std;


int main(void)
{
	int count;
	scanf("%d",&count);

	for(;count>0;count--)
	{
		int a,b,c,s=0;
		cin>>c;
		a=1;
		b=17;
		a=(a%b)*10;
		for(int i=0;i<c-1;i++)
		{
			a=(a%b)*10;
			s+=a/b;
		}
		cout<<a/b<<" "<<s<<endl;
	}
	return 0;
}
