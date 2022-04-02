#include <iostream>
using namespace std;


int main(){
    int T;
    string S;
    cin >> T;
    while(T--){
        cin >> S;
        bool any_even_number = false;
        for(int i=0;i<S.size();++i){
            if((S[i] - '0') % 2 == 0){
                any_even_number = true;
                break;
            }
        }
        if((S[S.size()-1] - '0')%2 == 0)
            cout << 0 << '\n';
        else if((S[0]-'0')%2 == 0)
            cout << 1 << '\n';
        else if(any_even_number)
            cout << 2 << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}