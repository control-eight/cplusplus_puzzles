#include <iostream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

class LockingTree {
public:
    LockingTree(vector<int>& parent): parent_(parent) {
        child_ = vector<vector<int>>(parent_.size());
        child_[0] = {};
        for (int i = 1; i < parent.size(); i++) {
            child_[parent[i]].push_back(i);
        }
        locks_ = vector<int>(parent.size());
    }

    bool lock(int num, int user) {
        if (locks_[num] == 0) {
            locks_[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (locks_[num] == user) {
            locks_[num] = 0;
            return true;
        }
        return false;
    }

    bool checkDescendant(int num) {
        if (locks_[num] != 0) {
            return true;
        }
        for (int child : child_[num]) {
            if (checkDescendant(child)) {
                return true;
            }
        }
        return false;
    }

    bool checkAncestors(int num) {
        if (num == -1) {
            return true;
        }
        if (locks_[num] != 0) {
            return false;
        }
        return checkAncestors(parent_[num]);
    }

    void unlockNodes(int num) {
        locks_[num] = 0;
        for (int child : child_[num]) {
            unlockNodes(child);
        }
    }

    bool upgrade(int num, int user) {
        if (locks_[num] != 0) {
            return false;
        }
        if (!checkDescendant(num)) {
            return false;
        }
        if (!checkAncestors(num)) {
            return false;
        }
        unlockNodes(num);
        locks_[num] = user;
        return true;
    }

private:
    vector<int>& parent_;
    vector<vector<int>> child_;
    vector<int> locks_;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

int main() {
    vector<int> parent = {-1,0,0,1,1,2,2};
    LockingTree lockingTree(parent);
    cout << lockingTree.lock(2,2) << endl;
    cout << lockingTree.unlock(2,3) << endl;
    cout << lockingTree.unlock(2,2) << endl;
    cout << lockingTree.lock(4,5) << endl;
    cout << lockingTree.upgrade(0,1) << endl;
    cout << lockingTree.lock(0,1) << endl;
    return 0;
}