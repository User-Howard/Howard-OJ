#include <iostream>
#include <vector>
using namespace std;


int main(){
    string A, B;
    cin >> A >> B;
    vector<int> Failure(A.size());
    cout << A << ' ' << B << '\n';
    Failure[0] = -1, Failure[1] = 1;
    for(int i=2;i<A.size();++i){
        if(A[i] == A[Failure[i-1]+1])
            Failure[i] = Failure[i-1] + 1;
        else
            Failure[i] = Failure[i-1];
    }
    for(int i=0;i<A.size();++i)
        cout << Failure[i] << " \n"[i==A.size()-1];

    return 0;
}