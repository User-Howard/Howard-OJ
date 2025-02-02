#include <iostream>
using namespace std;


int N;
int arr[1002][2];
int main() {
    cin >> N;
    for(int i=0;i<N;++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    arr[N][0] = arr[0][0], arr[N][1] = arr[0][1];

    int64_t area = 0;
    for(int i=0;i<N;++i) {
        area += 1LL*arr[i][0]*arr[i+1][1]-1LL*arr[i+1][0]*arr[i][1];
    }
    cout << abs(area) << '\n';
    return 0;
}
