#include <iostream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] >= nums[i]) {
                int delta = nums[i - 1] - nums[i] + 1;
                res += delta;
                nums[i] += delta;
            }
        }
        return res;
    }
};