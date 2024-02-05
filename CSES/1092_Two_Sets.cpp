#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;
    if(N%4==1 || N%4==2) {
        cout << "NO\n";
        return 0;
    }
    vector<int> v1, v2;
    for(int i=N;i>=4;i-=4) {
        v1.emplace_back(i-0);
        v1.emplace_back(i-3);
        v2.emplace_back(i-1);
        v2.emplace_back(i-2);
    }
    if(N%4==3) {
        v1.emplace_back(3);
        v2.emplace_back(1);
        v2.emplace_back(2);
    }
    cout << "YES\n";
    cout << v1.size() << '\n';
    for(int i:v1) cout << i << ' ';
    cout << '\n' << v2.size() << '\n';
    for(int i:v2) cout << i << ' ';
    cout << '\n';
    return 0;
}
