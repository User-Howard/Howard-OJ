#include <iostream>
using namespace std;


int rag(int a,int count)
{
	int s=1;
	for(;count>=1;count--)
	{
		s*=a;
	}
	return s;
}
int fina(int a)
{
	int r,z,i=1,s=0;
	for(r=10; a%r !=a ;i++,r*=10){}
	int v=i;
	int tts=0;
	for(;i>=1;i--)
		tts+=rag( (a%rag(10,i)-a%rag(10,i-1))/rag(10,i-1) ,v);
	return tts;
}
int main(void)
{
	int a,b;
	
	while(cin>>a>>b)
	{
		bool run=true;
		for(;a<b;a++)
		{
			if (fina(a)==a)
			{
				run=false;
				cout<<a<<" ";
			}
		}
		if (run)
			cout<<"none";
		cout<<endl;

	}
	return 0;
}
