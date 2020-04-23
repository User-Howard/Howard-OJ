#include<iostream>
using namespace std;


int main(void)
{
    int test;
    string output;
    while(scanf("%d",&test) != EOF)
    {
        output="";
        while(test)
        {
            if(test % 2)
                output="1"+output;
            else
                output="0"+output;
            test/=2;
        }
        cout<<output<<endl;
    }
    return 0;
}