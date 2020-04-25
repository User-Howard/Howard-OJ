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


string mixat(string a,string b)
{
  string c;
  int start,le;
  for(le=b.length();le>0;le--)
  {
    for(start=0;start<b.length();start++)
    {
      c="";
      for(int i=start;i<start+le;i++)
      {
        c+=b[i];
      }
      if(inat(a,c))
      {
        return c;
      }
    }
  }
  return "E";
}


int main(void)
{
  string a,b;
  cin>>a>>b;
  //a always bigger than b
  if(a<b)
    swap(a,b);
  if(inat(a,b))
    cout<<b;
  else if(a!=b && mixat(a,b)==a)
    cout<<"E";
  else
    cout<<mixat(a,b);

  return 0;
}
