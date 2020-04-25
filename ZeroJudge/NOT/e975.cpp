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
		
		if(a[i] == ' ')
		{
			Ans[i] = ' ';
		}
		
		
		else if(65 <= a[i] && a[i] <=90)
		{
			Ans[i] = (char)( a[i]+b);
			if(a[i]+b > 90)
				Ans[i] -= 26;		
		}
		else if(97 <= a[i] && a[i] <=122)
		{
			Ans[i] = (char)( a[i]+b);
			if(a[i]+b > 122)
				Ans[i] -= 26;			
			
		}
//		cout<<a[i]<<" "<<Ans[i]<<endl;
			
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
		if(get_(addd(str,i),"Love") || get_(addd(str,i),"love"))
		{
			printf("%d\n",i);
			return 0;
		}
		
	}
		
    return 0;
}
