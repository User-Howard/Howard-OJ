#include <iostream>
#include <vector>
using namespace std;

// N<=100000
// 1. why 'sum' runs in O(logN)?
// 2. simplify our segment tree
// 3. how to perform `add` in bottom-up?
// 4. solve this problem with divide&conquer

vector<int> SUM;

void init(int u, int lb, int rb){
    while (u >= (int)SUM.size()) SUM.push_back(0);
    if(lb < rb) {
        int m = (lb+rb) / 2;
        init(u*2, lb, m);
        init(u*2+1, m+1, rb);
    }
}

// [n->leftBor, n->rightBor] 與 [a, b] 必須有交集
// return t[a]+t[a+1]+...+t[b]
int sum(int u, int a, int b, int lb, int rb) {
    if(a <= lb && rb <= b) return SUM[u];
    int count = 0;
    int m = (lb + rb) / 2;
    if(a <= m) count += sum(2*u, a, b, lb, m);
    if(b > m) count += sum(2*u+1, a, b, m+1, rb);
    return count;
}

// [n->leftBor, n->rightBor] 與 [i, i] 必須有交集
// t[i] += x
void add(int u, int i, int x, int lb, int rb) {
    SUM[u] += x;
    if(lb != rb) {
        int m = (lb + rb) / 2;
        if(i <= m) {
          add(2*u, i, x, lb, m);
        } else {
          add(2*u+1, i, x, m+1, rb);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    //vector<int> t(n);
    init(1,0,n-1);
    long long answer = 0;
    for(int i = 0; i < 2*n; i++) {
        int num;
        cin >> num;
        num--;
        int count = 0;
        if(0 <= num-1) count = sum(1, 0, num-1, 0, n-1);
        if(sum(1, num, num, 0, n-1) == 1) answer += count;
        else answer -= count;
        add(1, num, 1, 0, n-1);
        //for(int j = 0; j < num; j++) {
        //    count += t[j];
        //}
        //if(++t[num] == 2) answer += count;
        //else answer -= count;
        
    }
    cout << answer << '\n';
    return 0;
}

/*
  1 2 3 4 5 6 7 8
A 4 2 1 3 2 1 4 3
  - - - - + + + +
T 1 2 1 1
*/

