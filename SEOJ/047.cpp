#include <iostream>
using namespace std;


struct Node{
    public:
    int data;
    Node *lc, *rc;
    Node(int x){
        data = x, lc = rc = NULL;
    }
}*root;
Node* insert(Node *r, int x){
    cout << "\t" << r->data << '\n';
    if(x == r->data)
        return r;
    if(r->lc != NULL and x < r->data){
        return insert(r->lc, x);
    }
    if(r->rc != NULL and x >= r->data){
        return insert(r->rc, x);
    }
    return r;
}
// Node* insert(Node *r, int x){
// }
int main(){
    root = new Node(1);
    root->rc = new Node(3);
    root->lc = new Node(-3);
    insert(root, 1);
    return 0;
}