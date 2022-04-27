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

int median(int N) {
    if (N % 2 == 0) {
        return N/2 - 1;
    }
    return N/2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        vector<int> B;
        for (int i = 0; i < 2 * N; i++) {
            B.push_back(Read<int>());
        }
        sort(B.begin(), B.end());

        if (N == 1) {
            if (B.back() != B.front()) {
                cout << -1 << endl;
            } else {
                cout << B.back() << endl;
            }
            continue;
        }

        vector<int> A;
        int m = median(2*N);
        for (int i = 0; i < B.size() - 1; i++) {
            if (B[i] == B[m]) {
                if (B[i] != B[i + 1] || B[i] != B[i + 2]) {
                    break;
                }
                A.push_back(B[i]);
                i+=2;
            } else {
                if (B[i] == B[i + 1]) {
                    A.push_back(B[i]);
                    i++;
                } else {
                    break;
                }
            }
        }
        if (B.back() == B[B.size() - 2] || A.size() < (N - 1)) {
            cout << -1 << endl;
            continue;
        }
        if (N % 2 == 0) {
            if (B[m] != B[m + 1] || B[m] != B[m - 1]) {
                cout << -1 << endl;
                continue;
            }
        } else {
            if (B[m] != B[m + 1] || B[m] != B[m + 2]) {
                cout << -1 << endl;
                continue;
            }
        }
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] == A[i+1]) {
                cout << -1 << endl;
                continue;
            }
        }
        A.push_back(B.back());
        for (int el : A) {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}