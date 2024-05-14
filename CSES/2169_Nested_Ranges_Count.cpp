#include <iostream>
#include <algorithm>
#include <istream>
#include <vector>
#include <set>
#include <map>
using namespace std;



const int MAX_N = 1e9;
struct BIT_tree{
    vector<int> bit;
    BIT_tree(int s){
        bit.resize(s+5);
    }
    void push(int i, int x){
        i += 1;
        for(;i<bit.size();i += i&-i)
            bit[i] += x;
    }
    int sum(int i){
        i += 1;
        int s=0;
        for(;i>0;i -= i&-i)
            s += bit[i];
        return s;
    }
    int range(int i, int j) {
        return sum(j)-sum(i-1);
    }
    void clear() {
        bit.assign(bit.size(), 0);
    }
    int size() {
        return bit.size();
    }
};
struct Range {
    int from, to;
    Range() {

    }
    Range(int from_, int to_) {
        from = from_;
        to = to_;
    }
    friend istream& operator>>(istream& in, Range& range) {
        in >> range.from >> range.to;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Range& range) {
        out << "From: " << range.from << ", To: " << range.to;
        return out;
    }
};
int main() {
    int N;
    cin >> N;
    vector<pair<Range, int> > Ranges(N);
    for(int i=0;i<N;++i) {
        cin >> Ranges[i].first ;
        Ranges[i].second = i;
    }
    set<int> st;
    for(auto i: Ranges) {
        st.insert(i.first.from);
        st.insert(i.first.to);
    }
    map<int, int> mp;
    int cnt = 0;
    for(int i: st) {
        mp[i] = ++cnt;
    }
    for(auto &i: Ranges) {
        i.first.from = mp[i.first.from];
        i.first.to = mp[i.first.to];
    }
    // cerr << st.size() << '\n';
    BIT_tree Tree(st.size()+2);
    vector<vector<int> > Answer(2, vector<int>(N));
    sort(Ranges.begin(), Ranges.end(), [](const pair<Range, int> &a, const pair<Range, int> &b) {
        if(a.first.from == b.first.from) return a.first.to > b.first.to;
        return a.first.from < b.first.from;
    });
    for(int i=0;i<N;++i) {
        Answer[1][Ranges[i].second] = Tree.range(Ranges[i].first.to, st.size()+1);
        Tree.push(Ranges[i].first.to, 1);
    }
    Tree.clear();
    sort(Ranges.begin(), Ranges.end(), [](const pair<Range, int> &a, const pair<Range, int> &b) {
        if(a.first.to == b.first.to) return a.first.from > b.first.from;
        return a.first.to < b.first.to;
    });
    /*
    for(auto i: Ranges) {
        cerr << i.first << '\t' << i.second << '\n';
    }
    */
    for(int i=0;i<N;++i) {
        Answer[0][Ranges[i].second] = Tree.range(Ranges[i].first.from, Ranges[i].first.to);
        Tree.push(Ranges[i].first.from, 1);
    }
    for(int i=0;i<N;++i) {
        cout << Answer[0][i] << ' ';
    }
    cout << '\n';
    for(int i=0;i<N;++i) {
        cout << Answer[1][i] << ' ';
    }
    cout << '\n';
    // 做完這題以後去編講義
    //

    return 0;
}
