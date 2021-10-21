#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>

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

    Node(int value, int size): value(value), size(size){
        left = nullptr;
        right = nullptr;
    }

    unique_ptr<Node> left;
    unique_ptr<Node> right;
    int value;
    int size;
    int max_size_left = -1;
    int max_size_right = -1;
};

void print(const vector<int> v) {
    cout << "[";
    for (int i : v) {
        cout << i << ", ";
    }
    cout << "]" << endl;
}

class Solution {
public:
    int chooseBest(int value, int floor, int ceil) {
        if (floor == -1) {
            return ceil;
        } else if (ceil == -1) {
            return floor;
        } else {
            if (abs(value - floor) == abs(value - ceil)) {
                return min(floor, ceil);
            } else if (abs(value - floor) < abs(value - ceil)) {
                return floor;
            } else {
                return ceil;
            }
        }
    }

    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        auto rng = std::default_random_engine{};
        std::shuffle(rooms.begin(), rooms.end(), rng);
        unique_ptr<Node> root = make_unique<Node>(rooms[0][0], rooms[0][1]);
        for (int i = 1; i < rooms.size(); i++) {
            root = std::move(insert(std::move(root), rooms[i][0], rooms[i][1]));
        }
        vector<int> result;
        for (auto q : queries) {
            int floor = findFloor(std::move(root), q[0], q[1]);
            int ceil = findCeil(std::move(root), q[0], q[1]);
            result.push_back(chooseBest(q[0], floor, ceil));
        }
        return result;
    }

    unique_ptr<Node> insert(unique_ptr<Node> parent, int value, int size) {
        if (parent == nullptr) {
            return make_unique<Node>(value, size);
        }
        if (parent->value == value) {
            return parent;
        }
        if (value < parent->value) {
            parent->max_size_left = max(parent->max_size_left, size);
            parent->left = std::move(insert(std::move(parent->left), value, size));
        } else {
            parent->max_size_right = max(parent->max_size_right, size);
            parent->right = std::move(insert(std::move(parent->right), value, size));
        }
        return parent;
    }

    int findFloor(const unique_ptr<Node>& parent, int value, int min_size) {
        if (parent == nullptr) {
            return -1;
        }
        if (parent->size >= min_size && parent->value == value) {
            return value;
        }
        if (parent->max_size_left >= min_size && value <= parent->value) {
            return findFloor(parent->left, value, min_size);
        }
        int floor = -1;
        if (parent->max_size_right >= min_size && value > parent->value) {
            floor = findFloor(parent->right, value, min_size);
        }
        if (floor != -1 && floor <= value) {
            return floor;
        } else if (parent->size >= min_size) {
            return parent->value;
        }
        if (parent->max_size_left >= min_size) {
            return findFloor(parent->left, value, min_size);
        }
        return -1;
    }

    int findCeil(const unique_ptr<Node>& parent, int value, int min_size) {
        if (parent == nullptr) {
            return -1;
        }
        if (parent->size >= min_size && parent->value == value) {
            return value;
        }
        if (parent->max_size_right >= min_size && value >= parent->value) {
            return findCeil(parent->right, value, min_size);
        }
        int ceil = -1;
        if (parent->max_size_left >= min_size && value < parent->value) {
            ceil = findCeil(parent->left, value, min_size);
        }
        if (ceil >= value) {
            return ceil;
        } else if (parent->size >= min_size) {
            return parent->value;
        }
        if (parent->max_size_right >= min_size) {
            return findCeil(parent->right, value, min_size);
        }
        return -1;
    }
};

int main() {
    Solution s;
    /*vector<vector<int>> rooms = {{2,2},{1,2},{3,2}};
    vector<vector<int>> queries = {{3,1},{3,3},{5,2}};
    auto res = s.closestRoom(rooms, queries);
    print(res);

    vector<vector<int>> rooms1 = {{1,4},{2,3},{3,5},{4,1},{5,2}};
    vector<vector<int>> queries1 = {{2,3},{2,4},{2,5}};
    auto res1 = s.closestRoom(rooms1, queries1);
    print(res1);*/

    vector<vector<int>> rooms2 = {{15,19},{11,10},{12,1},{17,6},{1,6},{10,21},{13,7},{14,25},{19,3},{9,11}};
    vector<vector<int>> queries2 = {{3,22}};
    //14
    auto res2 = s.closestRoom(rooms2, queries2);
    print(res2);

    return 0;
}