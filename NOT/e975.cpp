#include <iostream>
using namespace std;

bool get_(string a ,string b){
	bool isd;
	for(int i=0;i<a.size();i++)
	{
		isd=true;
		for(int j=0;j<b.size();j++)
		{
			if(a[i+j] != b[j])
				isd=false;
		}
		if(isd)
			return 1;

	}
	return 0;
}

string addd(string a, int b)
{
	char Ans[a.size()];
	for(int i=0;i<a.size();i++)
	{
		Ans[i] = (char)( a[i]+b );
	}
	return Ans;
}
int main(void)
{
	string str;
	
	getline(cin,str);
	for(int i=-26;i<=25;i++)
	{
		if(get_(addd(str,i),"Love") || get_(addd(str,i),"love"))
		{
			printf("%d",i>=0 ? i : 26+i);
			return 0;
		}
		
	}
		
    return 0;
}
