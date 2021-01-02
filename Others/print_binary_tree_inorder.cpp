#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<cmath>


int N;
const int MAX_N = pow(2, 16)+2;
struct node;
std::array<int, MAX_N>nums;
std::vector<node> arr;
void insert_to_node();
void conbine();
bool compare_node(const node, const node);


struct node {
    int val=0;
    int count=0;
    node* right=NULL;
    node* left= NULL;
};
bool compare_node(const node a, const node b) {
    return a.val < b.val;
}
int main(void){
    std::cin>>N;
    for (int i=0;i<N;++i) {
        std::cin>>nums[i];
        node new_node;
        new_node.val=new_node.count=nums[i];
        arr.push_back(new_node);
    }
    while (arr.size()) {
        sort(arr.begin(), arr.end(), compare_node);
        for(auto i:arr){
            std::cout<<i.val<<' ';
        }
    }
    return 0;
}
/*
#input::
5
16 8 8 4 4
#ouput::
88
*/