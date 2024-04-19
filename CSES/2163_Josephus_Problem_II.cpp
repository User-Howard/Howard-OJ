#include <iostream>
using namespace std;

const int MAX_N = 2e5 + 5;
struct Node {
  int l, mid, r;
  int sum;
} Tree[4*MAX_N];
void init(int u, int l, int r) {
    // cerr << u << '\t' << l << '\t' << r << '\n';
    Tree[u].l = l;
    Tree[u].r = r;
    Tree[u].mid = (l + r) / 2;
    if (l != r) {
        const int mid = (l + r) / 2;
        init(2*u, l, mid);
        init(2*u+1, mid+1, r);
    }
}
void update(int u, int pos, int x) {
    Tree[u].sum += x;
    if(Tree[u].l == Tree[u].r) return;
    if (pos<=Tree[u].mid) {
        update(2*u, pos, x);
    }
    else {
        update(2*u+1, pos, x);
    }
}
int query(int u, int pr) {
    // cerr << "(" << Tree[u].l << ", " << Tree[u].r << ")\tsum: " << Tree[u].sum << "\trest: " << pr << '\n';
    if(Tree[u].l == Tree[u].r) {
        return Tree[u].l;
    }

    int result;
    if(Tree[2*u].sum < pr) {
        result =  query(2*u+1, pr-Tree[2*u].sum);
    }
    else {
        result = query(2*u, pr);
    }
    return result;
}
int debug(int u, int pos) {
    if(Tree[u].l == Tree[u].r) return Tree[u].sum;
    if(pos <= Tree[u].mid )
        return debug(2*u, pos);
    else
        return debug(2*u+1, pos);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  init(1, 1, N);
  for(int i=1;i<=N;++i) {
      update(1, i, 1);
  }

  int pointer = 1;
  for(int i=N;i>0;--i) {
      pointer = (pointer+K)%i;
      if (pointer==0) pointer = i; // dont know how to optimize it
      int result = query(1, pointer);
      update(1, result, -1);
      cout << result << ' ';

  }
  cout << '\n';
  return 0;
}
