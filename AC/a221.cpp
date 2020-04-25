#include<iostream>
using namespace std;


int main(void)
{
	int count;
	scanf("%d\n",&count);
	for(int i=1;i<=count;i++)
	{
		bool nospace=true;
		string a,ano,b;
		getline(cin,a);
		getline(cin,b);
		for(int j=0;j<a.size();j++)
		{
			if(a[j] != ' ')
			{
				ano.push_back(a[j]);
			}
			else
			{
				nospace=false;
			}
		}
		if(ano == b && nospace)
		{
			printf("Case %d: Yes\n",i);
		}
		else if(ano == b && !nospace)
		{
			printf("Case %d: Output Format Error\n",i);
		}
		else
		{
			printf("Case %d: Wrong Answer\n",i);
		}
	}
	
	return 0;
}
