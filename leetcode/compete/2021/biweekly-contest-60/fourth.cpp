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

set<int> factorPrime(int num, vector<int>& primes) {
    set<int> res;
    while (num != 1) {
        bool found;
        for (int prime : primes) {
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

lli countWaysUntil(int mask, int i, vector<vector<int>>& dp, vector<vector<int>>& capList, int allmask) {
    if (mask == allmask) {
        return mask > 0? 1: 0;
    }
    if (i >= capList.size()) {
        return mask > 0? 1: 0;
    }
    if (dp[mask][i] != -1) {
        return dp[mask][i];
    }
    lli ways = 0;
    ways += countWaysUntil(mask, i + 1, dp, capList, allmask);
    ways %= mod;
    bool found = false;
    int new_mask = mask;
    for (int prime : capList[i]) {
        if (new_mask & (1 << prime)) {
            found = false;
            break;
        }
        found = true;
        new_mask |= 1 << prime;
    }
    if (found) {
        ways += countWaysUntil(new_mask, i + 1, dp, capList, allmask);
    }
    ways %= mod;
    return dp[mask][i] = ways;
}

int numberOfGoodSubsets(vector<int>& nums) {
    unordered_map<int, int> index;
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
    for (int i = 0; i < primes.size(); i++) {
        index[primes[i]] = i;
    }
    int allmask = 0;
    vector<vector<int>> capList;
    int mult = 0;
    unordered_map<int, set<int>> cache;
    for (int num: nums) {
        set<int> set;
        if (cache.find(num) != cache.end()) {
            set = cache[num];
        } else {
            set = factorPrime(num, primes);
        }
        if (num == 1) {
            mult++;
            continue;
        }
        if (set.empty()) {
            continue;
        }
        vector<int> els;
        for (int prime : set) {
            els.push_back(index[prime]);
            allmask |= 1 << index[prime];
        }
        capList.push_back(els);
        cache[num] = set;
    }
    vector<vector<int>> dp(allmask + 1, vector<int>(nums.size(), -1));
    int res = countWaysUntil(0, 0, dp, capList, allmask);
    for (int i = 0; i < mult; i++) {
        res *= 2;
        res %= mod;
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    cout << numberOfGoodSubsets(nums) << endl;
    vector<int> nums2 = {4, 2, 3, 15};
    cout << numberOfGoodSubsets(nums2) << endl;
    vector<int> nums3 = {1};
    cout << numberOfGoodSubsets(nums3) << endl;
    vector<int> nums4 = {18,28,2,17,29,30,15,9,12};
    cout << numberOfGoodSubsets(nums4) << endl;
    vector<int> nums6 = {6,6,1};
    cout << numberOfGoodSubsets(nums6) << endl;
    vector<int> nums5 = {6,1,6,5,6,11,17};
    cout << numberOfGoodSubsets(nums5) << endl;
    // 62
    return 0;
}