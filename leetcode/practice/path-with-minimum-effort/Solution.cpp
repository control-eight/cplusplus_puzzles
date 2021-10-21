#include <iostream>
#include <algorithm>
#include <vector>
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

struct Point {
    int i = -1;
    int j = -1;

    Point up() const {
        return {i - 1, j};
    }
    Point down() const {
        return {i + 1, j};
    }
    Point left() const {
        return {i, j - 1};
    }
    Point right() const {
        return {i, j + 1};
    }
};

struct Item {
    int cost = 0;
    Point p;

    bool operator<(const Item &o) const {
        return cost < o.cost;
    }
    bool operator>(const Item &o) const {
        return !(*this < o);
    }
};

using item_queue = priority_queue<Item, std::vector<Item>, std::greater<Item>>;

class Solution {
public:
    bool CheckPoint(const Point& p, const vector<vector<int>>& heights) {
        return p.i >= 0 && p.j >= 0 && p.i < heights.size() && p.j < heights[0].size();
    }

    void Proceed(vector<vector<int>>& visited, const Point& next, const Item& el,
                 const vector<vector<int>>& heights,
                 item_queue& queue) {
        if (CheckPoint(next, heights)) {
            int next_cost = abs(heights[next.i][next.j] - heights[el.p.i][el.p.j]);
            Item next_item = {next_cost, next};
            if (visited[next.i][next.j] == -1 || visited[next.i][next.j] > next_item.cost) {
                visited[next.i][next.j] = next_item.cost;
                queue.push(std::move(next_item));
            }
        }
    }

    int minimumEffortPath(const vector<vector<int>>& heights) {
        if (heights.size() == 0) {
            return 0;
        }
        vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size(), -1));
        item_queue next;
        next.push({0, 0, 0});
        visited[0][0] = 0;
        int ans = -1;
        while (!next.empty()) {
            Item el = next.top(); next.pop();
            ans = std::max(ans, el.cost);
            if (el.p.i == heights.size() - 1 && el.p.j == heights[0].size() - 1) {
                break;
            }
            Proceed(visited, el.p.up(), el, heights, next);
            Proceed(visited, el.p.down(), el, heights, next);
            Proceed(visited, el.p.left(), el, heights, next);
            Proceed(visited, el.p.right(), el, heights, next);
        };
        return ans;
    }
};

int main() {
    cout << Solution().minimumEffortPath({{1, 2, 1, 1, 1},
                                          {1, 2, 1, 2, 1},
                                          {1, 2, 1, 2, 1},
                                          {1, 2, 1, 2, 1},
                                          {1, 1, 1, 2, 1}}) << endl;
    cout << Solution().minimumEffortPath({{1,10,6,7,9,10,4,9}}) << endl;
    cout << Solution().minimumEffortPath({{1, 2, 2},
                                          {1, 1, 1},
                                          {2, 2, 1}}) << endl;
    cout << Solution().minimumEffortPath({{1}}) << endl;
    cout << Solution().minimumEffortPath({{1, 2, 2},
                                          {3, 8, 2},
                                          {5, 3, 5}}) << endl;
    cout << Solution().minimumEffortPath({{1, 2, 3},
                                          {3, 8, 4},
                                          {5, 3, 5}}) << endl;
    return 0;
}