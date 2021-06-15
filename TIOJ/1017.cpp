#include <iostream>
#include <cmath>
using namespace std;


const int MAX_N = 1e6;
int nums[MAX_N+2];
int re[MAX_N+2];
int le[MAX_N+2];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        for(int i=0;i<N;i++)
            cin >> nums[i];
        re[0] = nums[0], le[N-1] = nums[N-1];
        for(int i=1;i<N;i++){
            re[i] = max(re[i-1], nums[i]);
            le[N-1-i] = min(le[N-i], nums[N-1-i]);
        }
        int ans = 0;
        for(int i=1;i<N-1;i++)
            if(re[i]<=nums[i] && nums[i]<=le[i])
                ++ans;
        cout << ans << '\n';
    }
	return 0;
}

// finish time: 14	min, 41	sec, 18	hsec
