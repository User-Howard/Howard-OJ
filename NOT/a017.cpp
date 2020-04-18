#include<iostream>
using namespace std;


int main(void)
{
    ios::sync_with_stdio(false);
    string str;
    int sqrcount;
    while(cin>>str)
    {
        sqrcount=0;
        for(int i=0;i<str.size();i++)
            if(str[i] == '(')
                sqrcount++;
        cout<<sqrcount;
    }
    return 0;
}