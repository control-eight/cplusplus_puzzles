#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

struct Node {
    explicit Node(int id): id(id) {};
    int id;
    unordered_map<int, Node*> edges;
};

int traverse(const Node& root, vector<lli>& values, int level) {
    if (root.edges.empty()) {
        values[level]++;
    }
    int res = level;
    for (const auto node : root.edges) {
        node.second->edges.erase(root.id);
        res = std::max(res, traverse(*node.second, values, level + 1));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        int M = Read<int>();

        unordered_map<int, Node> nodes;
        vector<Node> list;
        list.reserve(50);

        nodes.insert({1, Node(1)});
        for (int i = 0; i < N - 1; i++) {
            int left = Read<int>();
            int right = Read<int>();

            if (nodes.find(left) == nodes.end()) {
                nodes.insert({left, Node(left)});
            }
            if (nodes.find(right) == nodes.end()) {
                nodes.insert({right, Node(right)});
            }

            auto leftNode = nodes.find(left);
            auto rightNode = nodes.find(right);

            leftNode->second.edges.insert({right, &(rightNode->second)});
            rightNode->second.edges.insert({left, &(leftNode->second)});
        }

        vector<lli> values(N, 0);
        int max_level = traverse(nodes.find(1)->second, values, 0);

        vector<lli> sums(max_level + 1, 0);
        sums[0] = 0;
        lli count = 0;
        for (int i = 0; i < max_level + 1; i++) {
            count += values[i];
            if (i > 0) {
                sums[i] = sums[i - 1] + count;
            }
        }

        lli prevEvent = 0;
        lli res = 0;
        for (int i = 0; i < M; i++) {
            lli event = Read<lli>();
            lli diff = event - prevEvent;
            if (diff > sums.size()) {
                res += sums[sums.size() - 1] + (diff - sums.size()) * count;
            } else {
                res += sums[diff - 1];
            }
            prevEvent = event;
        }

        cout << res << endl;
    }
    return 0;
}