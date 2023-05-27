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
    vector<int>nums((N / block_size + 1) * block_size, INF), blocks(N/block_size + 1, INF);
    for(int i=0;i<N;++i)
        cin >> nums[i];
    for(int i=0;i<N;++i)
        blocks[i/block_size] = min(blocks[i/block_size], nums[i]);
    int c, x, y;
    while(T--){
        cin >> c >> x >> y;
        if(c == 1){
            int min_ele = INF;
            int lb = x / block_size;
            int rb = y / block_size;

            if (lb == rb) {
                for (int i = x; i <= y; ++i)
                    min_ele = min(min_ele, nums[i]);
            }
            else {
                for (int i = x; i < (lb + 1) * block_size; ++i)
                    min_ele = min(min_ele, nums[i]);

                for (int i = lb + 1; i < rb; ++i)
                    min_ele = min(min_ele, blocks[i]);

                for (int i = rb * block_size; i <= y; ++i)
                    min_ele = min(min_ele, nums[i]);
            }

            cout << min_ele << '\n';
        }
        else{
            int block_index = x / block_size;
            nums[x] = y;
            blocks[block_index] = INF;

            for (int i = block_index * block_size; i < min((block_index + 1) * block_size, N); ++i)
                blocks[block_index] = min(blocks[block_index], nums[i]);
        }
        
    }
    return 0;
}