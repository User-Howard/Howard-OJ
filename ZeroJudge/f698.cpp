#include <iostream>
#include <cstring>
#include <stack>
using namespace std;


stack<int64_t> sta;
int64_t get_sta() {
    int64_t tmp = sta.top(); sta.pop();
    return tmp;
}
int main() {
    string c;
    while (cin >> c) {
        if (c=="+") {
            sta.push(get_sta()+get_sta());
        }
        else if (c=="-") {
            int a = get_sta();
            int b = get_sta();
            sta.push(b-a);
        }
        else if (c=="*") {
            sta.push(get_sta()*get_sta());
        }
        else if (c=="/") {
            int a = get_sta();
            int b = get_sta();
            sta.push(b/a);
        }
        else {
            sta.push(stoll(c));
        }
    }
    cout << sta.top() << '\n';
    return 0;
}