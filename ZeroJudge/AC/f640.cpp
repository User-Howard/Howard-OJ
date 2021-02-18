#include<iostream>
#include <cstdlib> //atoi()
#include<queue>
using namespace std;


queue<int> que; // (f, g, h) = (1001, 1002, 1003)
int arr_count = 0;
int spi();
int get_number() {
    int ret;
    if (que.front() <= 1000) {
        ret = que.front();
        que.pop();
    }
    else {
        ret = spi();
    }
    return ret;
}
int f() {
    return 2*(get_number()) - 3;
}
int g() {
    return 2*(get_number()) + (get_number()) - 7;
}
int h() {
    return 3*(get_number()) - 2*(get_number()) + get_number();
}
int spi() {
    int q = que.front();
    int ret;
    que.pop();
    if(q == 1001) {
        ret = f();
    }
    else if(q == 1002) {
        ret = g();
    }
    else if(q == 1003) {
        ret = h();
    }
    return ret;
}
int main() {
    string tmp;
    while (cin >> tmp) {
        if (tmp == "f")
            que.push(1001);
        else if (tmp == "g")
            que.push(1002);
        else if (tmp == "h")
            que.push(1003);
        else
            que.push(atoi(tmp.c_str()));
    }
    cout << spi() << endl;
    return 0;
}
/*
f(x) = 2x – 3
g(x, y) = 2x +y – 7
h(x, y, z) = 3x – 2y + z
*/