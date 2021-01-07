#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<cmath>


int N;
const int MAX_N = pow(2, 16)+2;
struct node;
std::array<int, (int)MAX_N>nums;
std::vector<node> arr;
int conbine(); 
bool compare_node(const node, const node);
int run_all_node(const node*, int);
node make_new_node(int, int);


struct node {
    int val=0;
    int count=0;
    node *right = NULL;
    node *left = NULL;
};
int conbine() { 
    if(arr.size()==1)
        return 0;
    sort(arr.begin(), arr.end(), compare_node);
    auto r = arr[0];
    auto l = arr[1];
    auto new_node = make_new_node(r.val+l.val, 0);
    new_node.left = &r;
    new_node.left = &l;
    arr.erase(arr.begin(), arr.begin()+2);
    arr.push_back(new_node);
}
bool compare_node(const node a, const node b) {
    return a.val < b.val;
}
node make_new_node(int val, int count=0){
    node new_node;
    new_node.val = val;
    new_node.count = count;
    return new_node;
}
int run_all_node(const node* N, int bit){
    int answer=0;
    answer+=bit * (N->count);
    if(N->right->val != 0)
        answer+=run_all_node(N->right, bit+1);
    if(N->left->val != 0)
        answer+=run_all_node(N->left, bit+1);
    std::cout<<"answer= "<<answer<<std::endl;
    return answer;
}
int main(void){
    std::cin>>N;

    for (int i=0;i<N;++i) {
        std::cin>>nums[i];
        node new_node;
        new_node.val=new_node.count=nums[i];
        arr.push_back(new_node);
    }
    while (conbine()) {
        for(auto i:arr){
            std::cout<<i.val<<' ';
        }
        std::cout<<std::endl;
    }
    std::cout<<arr.size()<<std::endl;
    auto rest = arr[0];
    std::cout<<run_all_node(&rest, 0)<<std::endl;
    return 0;
}
/*
#input::
5
16 8 8 4 4
#ouput::
88
*/