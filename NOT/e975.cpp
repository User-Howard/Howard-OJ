#include <iostream>
using namespace std;

bool solve(string a ,string b){
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
	for(int i=0;i<26;i++)
	{
		if(solve(addd(str,i),"Love") || solve(addd(str,i),"love"))
		{
			printf("%d",i);
			return 0;
		}
		
	}
		
    return 0;
}
