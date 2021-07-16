#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int R, C, M;
vector<vector<int> > un_spin(){ // 旋轉
    vector<vector<int> > ret(C, vector<int>(R, 0));
    
}
vector<vector<int> > un_flip(){ // 翻轉

}
int main(){
    cin >> R >> C >> M;
    vector<vector<int> > nums(R, vector<int>(C, 0));
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
            cin >> nums[i][j];
    nums = un_spin();
    return 0;
}