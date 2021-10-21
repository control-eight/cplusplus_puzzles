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
    int solve(int value, int maximumBit) {
        int result = 0;
        int i = 1;
        int j = 0;
        while (j < maximumBit) {
            //cout << i << endl;
            if (!(value & i)) {
                result |= i;
            }
            i <<= 1;
            j++;
        }
        return result;
    }

    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int value = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            value = value ^ nums[i];
        }
        vector<int> result;
        for (int i = nums.size() - 1; i >= 0; i--) {
            //cout << value << endl;
            result.push_back(solve(value, maximumBit));
            value = value ^ nums[i];
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v = {0,1,1,3};
    auto vv = s.getMaximumXor(v, 2);
    for (auto i : vv) {
        cout << i << " ";
    }
}