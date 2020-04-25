#include<iostream>
using namespace std;


int prime(int a)
{
	for(int i=2;i<a;i++)
	{
		if(a%i==0)
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	int times;
	cin>>times;
	for(;times>0;times--)
	{
		int a;
		cin>>a;
		
		//get len 
		int r,len=0;
		for(r=10; a%r !=a ;len++,r*=10){}len+=1;
		////
		
		//check
		bool tr=true;
		for(;r!=1;r/=10)
		{
			if(not prime(a%r))
			{
				tr=false;
			}
		}
		if(tr)
		{
			printf("%d is a Prime Day!\n",a);
		}
		else
		{
			printf("%d isn't a Prime Day!\n",a);
		}
	}
	
	return 0;
}
