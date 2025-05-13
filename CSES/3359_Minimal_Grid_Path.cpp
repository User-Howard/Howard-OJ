#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) cin >> S[i];

    vector<pair<int, int> > current;
    current.push_back({0, 0});
    string answer;
    answer += S[0][0];

    vector<vector<bool> > visited(N, vector<bool>(N));
    while (*current.begin()!=make_pair(N-1, N-1)) {
        char min_char = 'Z' + 1;
        
        vector<pair<int, int> > next;

        for (auto [x, y] : current) {
            if (x + 1 < N and not visited[x+1][y]) {
                min_char = min(min_char, S[x + 1][y]);
                visited[x+1][y] = true;
            }
            if (y + 1 < N and not visited[x][y+1]) {
                min_char = min(min_char, S[x][y + 1]);
                visited[x][y+1] = true;
            }
        }

        for (auto [x, y] : current) {
            if (x + 1 < N && S[x + 1][y] == min_char and visited[x+1][y]) {
                next.push_back({x + 1, y});
                visited[x+1][y] = false;
            }
            if (y + 1 < N && S[x][y + 1] == min_char and visited[x][y+1]) {
                next.push_back({x, y + 1});
                visited[x][y+1] = false;
            }
        }
        answer += min_char;
        current = move(next);
    }

    cout << answer << '\n';
    return 0;
}