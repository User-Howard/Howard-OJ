#include <iostream>
#include <list>
using namespace std;

string solve(string);

int main(void)
{
    ios::sync_with_stdio(false);
    string str;
    int sqrcount;
    while (cin >> str)
    {
        sqrcount = 0;
        for (int i = 0; i < str.size(); i++)
            if (str[i] == '(')
                sqrcount++;

        int ti = 0;
        for (int i = 0; i < str.size(); i++)
            ;

        //cout<<sqrcount;
    }
    return 0;
}

string solve(string a)
{
}