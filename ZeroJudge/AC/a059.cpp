#include<iostream>
using namespace std;


int main(void)
{
	int a,b,s=0;
	int d,c=0;
	cin>>c;
	
	for(d=1;d<=c;d++)
	{
		s=0;
		cin>>a>>b;
		int i=0;
		while (i*i<=b)
		{
			if(a<=i*i && i*i<=b)
				s+=i*i;

			i++;
		}
		printf("Case %d: %d\n",d,s);
	}

	return 0;
}
