#include <iostream>
#include <vector>
using namespace std;

struct E{
    E():is_word(false), cnt(0){}
    E* child[26];
    bool is_word;
    int cnt;
};
E root;
void add(E *r, string s, int x=0){
    r->cnt ++;
    if(x == s.size()){
        r->is_word = true;
        return;
    }
    if(r->child[s[x] - 'a'] == nullptr)
        r->child[s[x] - 'a'] = new E();
    add(r->child[s[x] - 'a'], s, x + 1);
    return;
}
bool find(E *r, string s, int x=0){
    if(x == s.size())
        return r->is_word;
    if(r->child[s[x] - 'a'] == nullptr)
        return false;
    else
        return find(r->child[s[x] - 'a'], s, x + 1);
}
int main(){
    string c, s;
    while(cin >> c >> s){
        if(c == "add"){
            add(&root, s);
        }
        else
            cout << (find(&root, s) ? "True":"False") << '\n';
    }
    return 0;
}