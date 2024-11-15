#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--) {
        static int x;
        cin >> x;
        int answer = 0;
        for(int i=1;i*i<=x;++i) {
            if(x%i == 0)
                answer += 2;
            if(i*i==x)
                answer -= 1;
        }
        cout << answer << '\n';
    }
    return 0;
}
