#include <iostream>
#include <stack>
#include <vector>
using namespace std;


stack<int> st;
vector<int> G[100];
void clear_stack(stack<int> *s){
    stack<int> *new_stack;
    swap(s, new_stack);
    return;
}
void init(){
    while(!st.empty())st.pop();

}
int main(){
    st.push(12);
    st.push(2121);
    clear_stack(&st);
    cout << st.empty();
    // int K;
    // cin >> K;
    // while(K--){

    // }
    return 0;
}