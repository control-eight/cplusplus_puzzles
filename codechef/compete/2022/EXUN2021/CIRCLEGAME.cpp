#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int M = Read<int>();
        int X = Read<int>();
        vector<int> ans;
        ans.push_back(1);
        int prev = 1;
        cout << 1 << " ";
        for (int i = 2; i <= X; i++) {
            int val;
            if (M == i) {
                val = i;
            } else if (i < M) {
                val = M % i;
            } else {
                val = M;
            }
            if (val == 0) {
                val = i;
            }

            if (prev == val) {
                val++;
            } else if (prev < val) {
                val = prev;
            } else {
                val = prev + 1;
            }
            cout << val << " ";
            prev = val;
        }
        cout << endl;
    }
    return 0;
}