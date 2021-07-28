#include <iostream>
#include <string>
#include <cmath>
using namespace std;



int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    string S;
    int p, a, b, c;
    getline(cin, S, ',');p = atoi(S.c_str());
    getline(cin, S, ',');a = atoi(S.c_str());
    getline(cin, S, ',');b = atoi(S.c_str());
    getline(cin, S, '\n');c = atoi(S.c_str());
    switch(p){
    case 1: {
        if (a == NULL)
            cout << sqrt(c * c - b * b) << '\n';
        else if (b == NULL)
            cout << sqrt(c * c - a * a) << '\n';
        else if (c == NULL)
            cout << sqrt(a * a + b * b) << '\n';
        break;
    }
    case 2: {
        if (a == NULL)
            cout << 0.5*c+b << '\n';
        else if (b == NULL)
            cout << a-0.5*c << '\n';
        else if (c == NULL)
            cout << 2*(a-b) << '\n';
        break;
    }
    case 3: {
        if (a == NULL)
            cout << c/b << '\n';
        else if (b == NULL)
            cout << c/a << '\n';
        else if (c == NULL)
            cout << a*b << '\n';
        break;
    }
    }
    return 0;
}