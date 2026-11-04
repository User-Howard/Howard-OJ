#include <iostream>
#include <vector>
using namespace std;


struct Node {
    vector<int> children;
    int operation;
    int val; // -1 if hasn't calculate
    int depth;
};
vector<Node> Nodes;
pair<int, int> dfs(int x) { // Return (depth, value)
    Node &node = Nodes[x];
    if(node.val != -1) {
        return {node.depth, node.val};
    }

    switch (node.operation) { // and, or, xor, not
        case 1: {
            int value = 1;
            int max_depth = 0;
            for(int v: node.children) {
                auto [child_depth, child_value] = dfs(v);
                value &= child_value;
                max_depth = max(child_depth+1, max_depth);
            }
            node.val = value;
            node.depth = max_depth;
            break;
        }
        case 2: {
            int value = 0;
            int max_depth = 0;
            for(int v: node.children) {
                auto [child_depth, child_value] = dfs(v);
                value |= child_value;
                max_depth = max(child_depth+1, max_depth);
            }
            node.val = value;
            node.depth = max_depth;
            break;
        }
        case 3: {
            int value = 0;
            int max_depth = 0;
            for(int v: node.children) {
                auto [child_depth, child_value] = dfs(v);
                value ^= child_value;
                max_depth = max(child_depth+1, max_depth);
            }
            node.val = value;
            node.depth = max_depth;
            break;
        }
        case 4: {
            int value = 0;
            int max_depth = 0;
            for(int v: node.children) {
                auto [child_depth, child_value] = dfs(v);
                value = !child_value;
                max_depth = max(child_depth+1, max_depth);
            }
            node.val = value;
            node.depth = max_depth;
            break;
        }
        default: {
            dfs(node.children.front());
            node.depth = Nodes[node.children.front()].depth;
            node.val = Nodes[node.children.front()].val;
            break;
        };
    }
    return {node.depth, node.val};
}
int main() {
    int P, Q, R, M;
    cin >> P >> Q >> R >> M;
    Nodes.assign(P+Q+R+1, (Node){.val = -1});
    for(int i=1; i<=P; ++i) {
        int tmp;
        cin >> tmp;
        Nodes[i].val = tmp;
    }
    for(int i=P+1; i<=P+Q; ++i) {
        int tmp;
        cin >> tmp;
        Nodes[i].operation = tmp;
    }
    for(int i=1; i<=M; ++i) {
        int a, b;
        cin >> a >> b;
        Nodes[b].children.emplace_back(a);
    }
    int max_depth = 0;
    vector<int> ans;
    for(int i=P+Q+1; i<=P+Q+R; ++i) {
        auto [depth, value] = dfs(i);
        max_depth = max(depth, max_depth);
        ans.emplace_back(value);
    }
    cout << max_depth << '\n';
    for(auto i: ans) cout << i << ' ';
    cout << '\n';
    return 0;
}
