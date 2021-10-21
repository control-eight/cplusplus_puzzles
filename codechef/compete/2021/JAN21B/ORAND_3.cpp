#include <iostream>
#include <vector>
#include <unordered_set>
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

void fwht_or(vector<int>& A, int dir = 1) {
    for (int s = 2, h = 1; s <= A.size(); s <<= 1, h <<= 1)
        for (int l = 0; l < A.size(); l += s)
            for (int i = 0; i < h; i++)
                A[l + h + i] += dir * A[l + i];
}


void fwht_and(vector<int>& A) {
    for (int s = 2, h = 1; s <= A.size(); s <<= 1, h <<= 1)
        for (int l = 0; l < A.size(); l += s)
            for (int i = 0; i < h; i++)
                A[l + i] += A[l + h + i];
}

void ifwht_and(int n, int *a, int *A) {
    std::copy(A, A + n, a);
    // If n is guaranteed to be a power of 2 then we don't need n_ and the min(...) in the inner loop.
    int n_ = 1; while (n_ < n) n_ <<= 1;
    for (int s = n_, h = n_ / 2; h; s >>= 1, h >>= 1)
        for (int l = 0; l < n; l += s)
            for (int i = 0; i < std::min(i, n - l - h); i++)
                a[l + i] -= a[l + h + i];
}

void fwht_xor(int n, int *a, int *A, bool inv = false) {
    std::copy(a, a + n, A);
    for (int s = 2, h = 1; s <= n; s <<= 1, h <<= 1) {
        for (int l = 0; l < n; l += s) {
            for (int i = 0; i < h; i++) {
                int t = A[l + h + i];
                A[l + h + i] = A[l + i] - t;
                A[l + i] += t;
                if (inv) A[l + h + i] /= 2, A[l + i] /= 2;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        int M = Read<int>();
        vector<int> as;
        while (N--) {
            as.push_back(Read<int>());
        }
        vector<int> bs;
        while (M--) {
            bs.push_back(Read<int>());
        }
        unordered_set<int> set = {0};

        vector<int> test = {3, 3};
        fwht_or(test, 1);
        for (int el : test) {
            cout << el << endl;
        }
        int C = 20;
        while(C--) {
            vector<int> all_as;
            all_as.reserve(set.size() + as.size());
            all_as.insert(all_as.end(), set.begin(), set.end());
            all_as.insert(all_as.end(), as.begin(), as.end());
            fwht_or(all_as, 1);

            vector<int> all_bs;
            all_bs.reserve(set.size() + bs.size());
            all_bs.insert(all_bs.end(), set.begin(), set.end());
            all_bs.insert(all_bs.end(), bs.begin(), bs.end());
            fwht_and(all_bs);

            set.insert(all_as.begin(), all_as.end());
            set.insert(all_bs.begin(), all_bs.end());
        }
        cout << set.size() << endl;
    }
    return 0;
}