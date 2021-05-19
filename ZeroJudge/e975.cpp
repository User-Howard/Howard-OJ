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
		
		Ans[i] = a[i];
		for(int j=0;j<b;j++)
		{
			Ans[i]++;
			if(Ans[i] == 'z'+1)
				Ans[i] -= 26;
			else if(Ans[i] == 'Z'+1)
				Ans[i] -= 26;
		}
					
	}
	return Ans;
}
int main(void)
{
	string str;
//	cout<<addd("NqxgRgceg" ,24)<<endl;
//	cout<<"NqxgRgceg"<<endl;
	getline(cin,str);
	for(int i=0;i<=25;i++)
	{
		//cout<<addd(str,i)<<endl;
		if(get_(addd(str,i),"Love") || get_(addd(str,i),"love"))
		{
			printf("%d\n",i);
			break;
		}
		
	}
		
    return 0;
}
