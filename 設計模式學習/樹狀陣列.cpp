#include <vector>
struct BIT_tree{
    std::vector<int>bit;
    BIT_tree(int s){bit.resize(s);}
    void push(int i, int x){
        for(;i<bit.size();i += i&-i)
            bit[i] += x;
    }
    int sum(int i){
        int s=0;
        for(;i>0;i -= i&-i)
            s += bit[i];
        return s;
    }

};