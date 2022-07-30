#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N;
    cin >> T >> N;
    int block_size = sqrt(N);
    vector<int>nums((N / block_size + 1) * block_size), blocks(N/block_size + 1, INF);
    for(int &i:nums) cin >> i;
    for(int i=0;i<N;++i)
        blocks[i/block_size] = min(blocks[i/block_size], nums[i]);
    int c, x, y;
    while(T--){
        cin >> c >> x >> y;
        if(c == 1){
            int min_ele = INF;
            int lb = x / block_size, rb = y / block_size;
            for(int i=0;i<block_size;++i){
                if(x <= lb*block_size+i)
                    min_ele = min(min_ele, nums[lb*block_size+i]);
                if(rb*block_size+i <= y)
                    min_ele = min(min_ele, nums[rb*block_size+i]);
            }
            for(int i=lb+1;i<rb;++i)
                min_ele = min(min_ele, blocks[i]);
            cout << min_ele << '\n';
        }
        else{
            nums[x] = y;
            int min_ele = INF;
            for(int i=0;i<block_size;++i){
                min_ele = min(min_ele, nums[x / block_size + i]);
            }
            blocks[x / block_size] = min_ele;
        }
    }
    return 0;
}