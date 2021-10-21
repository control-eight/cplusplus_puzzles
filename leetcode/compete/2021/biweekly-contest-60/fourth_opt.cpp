#include <iostream>
#include <iostream>
#include <vector>
#include <set>
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

set<int> factorPrime(int num, vector<int> &primes) {
    set<int> res;
    while (num != 1) {
        bool found;
        for (int prime: primes) {
            if (num % prime == 0) {
                if (res.find(prime) != res.end()) {
                    return {};
                }
                res.insert(prime);
                num /= prime;
                found = true;
            }
        }
        if (!found) return {};
    }
    return res;
}

// caps - elements
// assign to
// persons - prime factors

lli mod = 1000000007;

lli countWaysUntil(unordered_map<int, int> &capList, int allmask) {
    vector<lli> dp(allmask + 1, -1);
    dp[0] = 0;
    lli res = 0;
    for (auto&[num, c]: capList) {
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] != -1) {
                if (!(i & num)) {
                    int new_mask = i | num;
                    if (dp[new_mask] == -1) {
                        dp[new_mask] = 0;
                    }
                    lli count = c * (dp[i] == 0 ? 1 : dp[i]);
                    dp[new_mask] += count;
                    dp[new_mask] %= mod;
                    res += count;
                    res %= mod;
                }
            }
        }
    }
    return res;
}

int numberOfGoodSubsets(vector<int> &nums) {
    unordered_map<int, int> index;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (int i = 0; i < primes.size(); i++) {
        index[primes[i]] = i;
    }
    vector<int> nums_set(31);
    for (int num: nums) {
        nums_set[num]++;
    }
    int allmask = 0;
    unordered_map<int, int> capList;
    for (int i = 2; i < nums_set.size(); i++) {
        if (nums_set[i] != 0) {
            set<int> my_set = factorPrime(i, primes);
            if (my_set.empty()) {
                continue;
            }
            int mask = 0;
            for (int prime: my_set) {
                allmask |= 1 << index[prime];
                mask |= 1 << index[prime];
            }
            capList[mask] = nums_set[i];
        }
    }
    lli res = countWaysUntil(capList, allmask);
    for (int i = 0; i < nums_set[1]; i++) {
        res *= 2;
        res %= mod;
    }
    return res;
}

int main() {
    vector<int> nums0 = {5, 10, 1, 26, 24, 21, 24, 23, 11, 12, 27, 4, 17, 16, 2, 6, 1, 1, 6, 8, 13, 30, 24, 20, 2, 19};
    cout << numberOfGoodSubsets(nums0) << endl;
    vector<int> nums = {1, 2, 3, 4};
    cout << numberOfGoodSubsets(nums) << endl;
    vector<int> nums2 = {4, 2, 3, 15};
    cout << numberOfGoodSubsets(nums2) << endl;
    vector<int> nums3 = {1};
    cout << numberOfGoodSubsets(nums3) << endl;
    vector<int> nums4 = {18, 28, 2, 17, 29, 30, 15, 9, 12};
    cout << numberOfGoodSubsets(nums4) << endl;
    vector<int> nums6 = {6, 6, 1};
    cout << numberOfGoodSubsets(nums6) << endl;
    vector<int> nums5 = {6, 1, 6, 5, 6, 11, 17};
    cout << numberOfGoodSubsets(nums5) << endl;
    // 62
    return 0;
}