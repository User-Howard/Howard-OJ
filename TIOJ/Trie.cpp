#include <iostream>
#include <vector>
using namespace std;

class Trie{
    Trie():__root(new TrieNode){}
    public:
        nu __root;
    private:
        struct TrieNode {
            TrieNode():is_word(false), children(26, nullptr){}
        
            ~TrieNode() {
                for (TrieNode* child : children)
                    if (child) delete child;
            }
            bool is_word;
            vector<TrieNode*> children;
        };
};
int main(){
    Trie root;
    cout << root.root->is_word;
    return 0;
}