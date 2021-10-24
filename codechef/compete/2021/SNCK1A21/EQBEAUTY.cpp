#include <iostream>
#include <vector>
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

lli calc(const vector<lli>& v) {
    lli bestSoFar = 1e18;
    for (int i = 2; i < v.size() - 1; i++) {
        lli diff = std::abs((v[v.size() - 1] - v[i]) - (v[i - 1] - v[0]));
        bestSoFar = std::min(diff, bestSoFar);
    }
    return bestSoFar;
}

lli calc2p1(const vector<lli>& v) {
    lli pp = 1 + (v.size() - 1) / 2;
    lli median = (v.size() - 1) % 2 == 0? (v[pp - 1] + v[pp]) / 2: v[v.size() / 2];
    lli ans1 = 0;
    for (int i = 1; i < v.size(); i++) {
        ans1 += std::abs(v[i] - median);
    }
    return ans1;
}

lli calc2p2(const vector<lli>& v) {
    lli pp1 = (v.size() - 1) / 2;
    lli median1 = (v.size() - 1) % 2 == 0? (v[pp1 - 1] + v[pp1]) / 2: v[v.size() / 2 - 1];
    lli ans2 = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        ans2 += std::abs(v[i] - median1);
    }
    return ans2;
}

lli calc2(const vector<lli>& v) {
    return std::min(calc2p1(v), calc2p2(v));
}

lli closest(lli v1, lli v2, lli target) {
    if (target - v1 >= v2 - target) {
        return v2;
    } else {
        return v1;
    }
}

int findClosest(const vector<lli>& v, lli lo, lli hi, lli target) {
    if (target <= v[lo]) {
        return v[lo];
    }
    if (target >= v[hi - 1]) {
        return v[hi - 1];
    }
    lli mid = 0;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (v[mid] == target) {
            return v[mid];
        }
        if (target < v[mid]) {
            if (mid > 0 && target > v[mid - 1]) {
                return closest(v[mid - 1], v[mid], target);
            }
            hi = mid;
        } else {
            if (mid < hi - 1 && target < v[mid + 1]) {
                return closest(v[mid], v[mid + 1], target);
            }
            lo = mid + 1;
        }
    }
    return v[mid];
}

lli calc3(const vector<lli>& v) {
    vector<lli> diff;
    for (int i = 2; i < v.size() - 1; i++) {
        diff.push_back(v[i] - v[0]);
    }
    lli bestSoFar = 1e18;
    for (int i = 1; i < v.size() - 2; i++) {
        lli diff1 = v[v.size() - 1] - v[i];
        bestSoFar = std::min(bestSoFar, std::abs(diff1 - findClosest(diff, i - 1, diff.size(), diff1)));
    }
    return bestSoFar;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        vector<lli> v;
        v.reserve(N);
        for (int i = 0; i < N; i++) {
            v.push_back(Read<lli>());
        }
        if (v.size() == 2) {
            cout << 0 << endl;
        } else {
            sort(v.begin(), v.end());
            cout << std::min(std::min(calc(v), calc2(v)), calc3(v)) << endl;
        }
    }
    return 0;
}