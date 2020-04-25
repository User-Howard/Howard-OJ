#include<iostream>
using namespace std;


int main(void)
{
	int a,count;
	while (cin>>count)
	{
		for(a=0;a<1;a++)
		{
			int i,s,n;
			s=0;
			for(i=0;i<count;i++)
			{
				cin>>n;
				s+=n;
			}
			if(s>59*count)
			{
				cout<<"no"<<endl;
			}
			else
			{
				cout<<"yes"<<endl;
			}
		}
	}
	return 0;
}