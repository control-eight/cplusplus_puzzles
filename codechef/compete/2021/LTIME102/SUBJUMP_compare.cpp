#include <iostream>
#include <iostream>
#include <vector>
#include <limits>
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

lli calc2(vector<lli> A) {
    lli ans = 0;
    int prev = 0;
    for (int i = 0; i < A.size() - 1; i++) {
        if (A[i] < A[prev]) {
            ans += (i - prev + 1) * A[prev] - A[i];
            prev = i;
        }
    }
    ans += (A.size() - prev) * A[prev] - A[A.size() - 1];
    return ans < 0? 0: ans;
}

lli calc_right(vector<lli> A, int index, unordered_map<int, lli>& cache) {
    if (index == A.size() - 1) {
        return 0;
    }
    if (cache.find(index) != cache.end()) {
        return cache[index];
    }
    lli ans = std::numeric_limits<lli>::max();
    for (int i = index + 1; i < A.size(); i++) {
        lli res = calc_right(A, i, cache) + ((i - index + 1) * A[index] - A[i]);
        ans = std::min(ans, res);
    }
    cache[index] = ans;
    return ans;
}

std::vector<lli> generateRandomArray(int n, int max) {
    std::vector<lli> res;
    for (int i = 0; i < n; i++) {
        res.push_back((rand() % max + 1));
    }
    sort(res.begin(), res.end());
    return res;
}

void print(const std::vector<lli>& all) {
    for (lli a : all) {
        cout << a << " ";
    }
    cout << endl;
}

int main() {
    srand(time(NULL));
    int maxN = 15;
    int maxA = 5;
    for (int i = 0; i < 1000; i++) {
        int n = (rand() % maxN + 1);
        std::vector<lli> all = generateRandomArray(n, maxA);
        lli res1 = calc2(all);
        unordered_map<int, lli> cache;
        lli res2 = calc_right(all, 0, cache);
        res2 = res2 <= 0? 0: res2;
        if (res1 != res2) {
            cout << res1 << " != " << res2 << endl;
            print(all);
        }
    }
    return 0;
}