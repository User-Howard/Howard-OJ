#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    map<char, int> li;
    li.clear();
    string a;
    int arc = 0;
    while (cin >> a)
    {
        li.clear();
        for (int i = 0; i < a.length(); i++)
            li[tolower(a[i])]++;

        arc = 0;
        for (int i = 97; i <= 122; i++)
        {
            if(li[(char)i] % 2 != 0)
                arc++;
        }
        printf("%s", arc<=1 ? "yes !\n" :"no...\n");
    }

    return 0;
}

/*
for python:

print(int(input()[::-1]))

*/