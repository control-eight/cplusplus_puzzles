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

lli calc(vector<lli> A, int index, unordered_map<int, lli>& cache) {
    if (index == A.size() - 1) {
        return 0;
    }
    if (cache.find(index) != cache.end()) {
        return cache[index];
    }
    lli ans = std::numeric_limits<lli>::max();
    for (int i = index + 1; i < A.size(); i++) {
        lli res = calc(A, i, cache) + ((i - index + 1) * A[index] - A[i]);
        ans = std::min(ans, res);
    }
    cache[index] = ans;
    return ans;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        vector<lli> A;
        for (int i = 0; i < N; i++) {
            A.push_back(Read<lli>());
        }
        unordered_map<int, lli> cache;
        lli res = calc2(A);
        cout << (res < 0? 0: res) << endl;
    }
    return 0;
}