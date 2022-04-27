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

int median(int n) {
    return (n + 2) / 2 - 1;
}

lli calc(const std::vector<lli>& all, int n, int target) {
    lli cost = 0;
    int m = median(n);
    for (int i = 0; i < n; i++) {
        target = std::max(m * (i + 1) + i, target);
        cost += all[target];
        target++;
    }
    return cost;
}

lli calcBinSearch(const std::vector<lli>& all, int n, lli k) {
    int lo = median(n);
    int hi = static_cast<int>(all.size()) - (n - median(n)) * n + 1;
    lli maxSoFar = -1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        lli cost = calc(all, n, mid);
        if (cost <= k) {
            maxSoFar = std::max(maxSoFar, all[mid]);
        }
        if (cost >= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return maxSoFar;
}

void print(const std::vector<lli>& all) {
    for (lli a : all) {
        cout << a << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int n = Read<int>();
        lli k = Read<lli>();

        std::vector<lli> all;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                all.push_back(Read<lli>());
            }
        }
        sort(all.begin(), all.end());
        //print(all);
        cout << calcBinSearch(all, n, k) << endl;
    }
    return 0;
}