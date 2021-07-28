#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N;
vector<int> A;
vector<bool>check;
bool are_correct_input(){
    vector<bool> check_case;
    check_case.resize(N + 1);
    for (int i=1;i<=N;i++) {
        check_case[A[i]] = true;
        if (A[i] == i) 
            return false;
    }
    if (!all_of(next(begin(check_case)), end(check_case), [](bool i) { return i; })) {
        return false;
    }
    return true;
}
void find(int n){
    if(!check[n]){
        check[n] = true;
        find(A[n]);
    }
}
int solve(){
    check.resize(N+1);
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(!check[i]){
            find(i);
            ++ans;
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    A.resize(N+1);
    for (int i=1;i<=N;i++)
        cin >> A[i];
    if(!are_correct_input()){
        cout << -1 << '\n';
        return 0;
    }
    cout << solve() << '\n';
    return 0;
}