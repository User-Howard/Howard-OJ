#include <iostream>
using namespace std;

int main(void)
{
    string a;
    int b;
    while (getline(cin, a) && a != "EOF")
    {
        for (int i = 0; i < a.length(); i++)
        {
            b = (int)a[i] - 7;
            cout << (char)b;
        }
        cout << endl;
    }
    return 0;
}
