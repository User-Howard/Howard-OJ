//
//  1. 邏輯運算子(Logic Operators).cpp
//  APCS
//
//  Created by 吳浩瑋 on 2022/8/27.
//
#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int > nums(3);
    for(int &i:nums) cin >> i;
    for(int &i:nums) i = (i >= 1);
    bool flag = false;
    if((nums[0] and nums[1]) == nums[2]) {
        flag = true;
        cout << "AND" << '\n';
    }
    if((nums[0] or nums[1]) == nums[2]) {
        flag = true;
        cout << "OR" << '\n';
    }
    if((nums[0] xor nums[1]) == nums[2]) {
        flag = true;
        cout << "XOR" << '\n';
    }
    if(!flag)
        cout << "IMPOSSIBLE" << '\n';
    return 0;
}