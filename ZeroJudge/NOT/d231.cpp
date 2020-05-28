#include<iostream>
using namespace std;


bool inat(string a,string b)
{
  	for(int i=0;i<a.length()-b.length()+1;i++)
  	{
    	int count=0;
    	for(int j=0;j<b.length();j++)
    	{
    		if(b[j] == a[j+i])
    	    count += 1;
    	}
    	if(count == b.length())
      		return true;
  	}
  	return false;
}



int main(void)
{
  	string a, b;
  	int i, j;
  	cin>>a>>b;
  	if(a<b)
    	swap(a,b);
    
  	if(inat(a,b))
    	cout<<b;
  	else{
		
  	}

  return 0;
}
