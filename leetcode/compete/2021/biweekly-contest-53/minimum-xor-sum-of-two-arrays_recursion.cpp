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

    int Calc(const vector<int>& nums1, const vector<int>& nums2, const int i, vector<vector<int>>& dp, const int mask) {
        if (i >= nums1.size()) {
            return 0;
        }
        if (dp[i][mask] != -1) {
            return dp[i][mask];
        }
        int ans = INT_MAX;
        for (int j = 0; j < nums2.size(); j++) {
            if (mask & (1 << j)) {
                int new_mask = mask ^ (1 << j);
                ans = min(ans, (nums1[i] ^ nums2[j]) + Calc(nums1, nums2, i + 1, dp, new_mask));
            }
        }
        return dp[i][mask] = ans;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int dp_size = (1 << n) - 1;
        vector<vector<int>> dp(n, vector<int>(dp_size + 1, -1));
        return Calc(nums1, nums2, 0, dp, dp_size);
    }
};

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {2, 3};

    vector<int> nums11 = {1, 0, 3};
    vector<int> nums22 = {5, 3, 4};

    vector<int> nums111 = {72, 97,8, 32, 15};
    vector<int> nums222 = {63, 97, 57, 60, 83};

    Solution s;
    cout << s.minimumXORSum(nums1, nums2) << endl;
    cout << s.minimumXORSum(nums11, nums22) << endl;
    // 152
    cout << s.minimumXORSum(nums111, nums222) << endl;

    return 0;
}