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

int findMiddleIndex(vector<int>& nums) {
    int sum = 0;
    for (int s : nums) {
        sum += s;
    }
    int left_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (left_sum == sum - left_sum - nums[i]) {
            return i;
        }
        left_sum += nums[i];
    }
    return -1;
}

int main() {
    vector<int> nums = {2,3,-1,8,4};
    cout << findMiddleIndex(nums) << endl;
    vector<int> nums1 = {1};
    cout << findMiddleIndex(nums1) << endl;
    return 0;
}