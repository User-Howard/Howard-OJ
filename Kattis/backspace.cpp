#include <iostream>
using namespace std;


int main() {
    string S, R;
    getline(cin, S);
    for(char c: S) {
        if(c=='<') {
            if(not R.empty()) {
                R.pop_back();
            }
        } else {
            R.push_back(c);
        }
    }
    cout << R << '\n';
    return 0;
}