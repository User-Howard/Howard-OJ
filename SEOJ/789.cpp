#include <iostream>
#include <vector>
using namespace std;


int N;
vector<int> vec;
void div(int n){
    if(vec.size() >= N){
       return;
    }
    
}
int main(){
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    cin >> N;
    int n = 3;
    while(n < N){
        vec.resize(2*n);
        for(int i=0;i<n;++i){
            vec[i+n] = 2*vec[i];
            vec[i] = 2*vec[i] - 1;
        }
        n *= 2;
    }
        for(int i=0;i<vec.size();++i){
            if(vec[i] <= N)
                cout << vec[i] << ' ';
        }
        cout << '\n';
     return 0;
}