#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


string S;
vector<pair<int, char>>cnt;
bool cmp(pair<int, char>a, pair<int, char>b){
    return a.first>b.first;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> S;
    for(int i=0;i<26;i++)
        cnt.push_back(make_pair(0, 'A'+i));
    for(char c:S)
        cnt[c-'A'].first += 1;
    stable_sort(cnt.begin(), cnt.end(), cmp);
    for(int i=0;i<26;i++){
        if(cnt[i].first==0)
            break;
        cout <<cnt[i].second;

    }
    cout<<'\n';
    return 0;
}

