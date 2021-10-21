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

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        lli s = 0;
        for (int el : nums) {
            s += el;
        }
        int res = 0;
        unordered_map<lli, vector<int>> els;
        lli ss = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            lli diff = ss - (s - ss);
            if (diff == 0) {
                res++;
            } else {
                els[diff].push_back(i - 1);
            }
            ss += nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            int r = 0;
            int t1 = nums[i] - k;
            auto& els_t1 = els[t1];
            auto el1 = lower_bound(els_t1.begin(), els_t1.end(), i);
            r += (el1 != els_t1.end())?  els_t1.end() - el1: 0;
            int t2 = k - nums[i];
            auto& els_t2 = els[t2];
            auto el2 = lower_bound(els_t2.begin(), els_t2.end(), i);
            r += (el2 != els_t2.end())? el2 - els_t2.begin(): els_t2.size();
            res = std::max(res, r);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v7 = {0,0,-1,0,0,0};
    cout << s.waysToPartition(v7, -1) << endl;
    vector<int> v6 = {0,0,0,0,0,0,0,0,0,-4732,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout << s.waysToPartition(v6, -4732) << endl;
    vector<int> v = {2, -1, 2};
    cout << s.waysToPartition(v, 3) << endl;
    vector<int> v3 = {0,0,30827,0,0};
    cout << s.waysToPartition(v3, 0) << endl;
    vector<int> v0 = {0,0,0,-71,-5,0};
    cout << s.waysToPartition(v0, 76) << endl;
    vector<int> v1 = {0, 0, 0};
    cout << s.waysToPartition(v1, 1) << endl;
    vector<int> v2 = {22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14};
    cout << s.waysToPartition(v2, -33) << endl;
    vector<int> v4 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-71,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-5,0};
    cout << s.waysToPartition(v4, 76) << endl;
    vector<int> v5 = {0,0,-71,0,0,-5,0};
    cout << s.waysToPartition(v5, 76) << endl;
    return 0;
}