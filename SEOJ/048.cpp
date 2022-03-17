#include<iostream>
using namespace std;


struct Node {
    uint64_t val;
    Node* lch, * rch;
};
Node* insert(Node* p, uint64_t x){
    if (p == NULL){
        Node* q = new Node;
        q->lch = q->rch = NULL;
        q->val = x;
        return q;
    }else{
        if (x < p->val)
            p->lch = insert(p->lch, x);
        else
            p->rch = insert(p->rch, x);
        return p;
    } 
}
void walk(Node* p){
    if(p->lch != NULL)
        walk(p->lch);
    if(p->rch != NULL)
        walk(p->rch);
    cout << p->val << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, n;
    Node *root = NULL; 
    cin >> N;
    for(int i=0;i<N;++i){
        cin >> n;
        root = insert(root, n);
    }
    walk(root);
    return 0;
}