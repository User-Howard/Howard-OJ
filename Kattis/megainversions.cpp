#pragma GCC optimize("Ofast,no-stack-protector")
#include <iostream>
#include <vector>
#define int long long
#define quick ios::sync_with_stdio(0);cin.tie(0);
#define rep(x,a,b) for(int x=a;x<=b;x++)
#define repd(x,a,b) for(int x=a;x>=b;x--)
#define lowbit(x) (x&-x)
#define sz(x) (int)(x.size())
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define eb emplace_back
using namespace std;
typedef pair<int,int> pii;
void debug(){
    cout<<"\n";
}
template <class T,class ... U >
void debug(T a, U ... b){
    cout<<a<<" ",debug(b...);
}
const int INF=1e18;

class BIT {
    vector<int> data;
    size_t size;
public:
    BIT(int size) {
        data.assign(size+10, 0);
        this->size = size+10;
    }
    void update(int pos, int val) {
        pos += 3;
        for(;pos<size;pos+=lowbit(pos)) {
            data[pos] += val;
        }
    }
    int query(int pos) {
        pos += 3;
        int result = 0;
        for(;pos>0;pos-=lowbit(pos)) {
            result += data[pos];
        }
        return result;
    }
};
signed main(){
    quick
    int N;
    cin >> N;
    vector<int> Nums(N);
    for(int &i: Nums) cin >> i;
    for(int &i: Nums) i = N-i;
    // for(int i: Nums) cerr << i << ' ';
    // cerr << '\n';
    BIT bt(N);
    vector<int> second_Nums(N);
    for(int i=0;i<N;++i) {
        second_Nums[i] = bt.query(Nums[i]-1);
        bt.update(Nums[i], 1);
    }
    // for(int i: second_Nums) {
    //     cerr << i << ' ';
    // } cerr << '\n';
    BIT bt2(N);
    int answer = 0;
    for(int i=0;i<N;++i) {
        answer += bt2.query(Nums[i]-1);
        bt2.update(Nums[i], second_Nums[i]);
    }
    cout << answer << '\n';
    return 0;
}