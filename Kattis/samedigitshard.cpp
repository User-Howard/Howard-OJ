#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A, B;
bool good(int a, int b) {
    int D[10] = {0};
    int ab = a*b;
    while(a) {
        D[a%10]++;
        a /= 10;
    }
    while(b) {
        D[b%10]++;
        b /= 10;
    }
    while(ab) {
        D[ab%10]--;
        ab /= 10;
    }
    for(int i=0;i<10;++i) {
        if(D[i]!=0) return false;
    }
    return true;
}
int intSize(int x) {
    int si = 0;
    while(x) {
        x /= 10;
        si++;
    }
    return si;
}
int main(){
    scanf("%d%d", &A, &B);
    vector<pair<int, int> > answer;
    for(int i=A;i*i<=B;++i) {
        for(int j=i;j<B;++j) {
            // if(intSize(i)+intSize(j)<intSize(i*j)) break;
            if(i*j > B) break;
            if(good(i, j)) {
                answer.push_back(make_pair(i, j));
            }
        }
    }
    printf("%d digit-preserving pair(s)\n", answer.size());
    for(auto i: answer) {
        printf("x = %d, y = %d, xy = %d\n", i.first, i.second, i.first*i.second);
    }
    return 0;
}