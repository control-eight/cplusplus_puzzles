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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        vector<int> A;
        int N = Read<int>();
        while (N--) {
            A.push_back(Read<int>());
        }
        std::vector<int> ends_with_ones;
        std::vector<int> ends_with_zeros;
        for (int i : A) {
            if (i % 2 == 1) {
                ends_with_ones.push_back(i);
            } else {
                ends_with_zeros.push_back(i);
            }
        }
        vector<int> res;
        for (int i : ends_with_zeros) {
            res.push_back(i);
        }
        for (int i : ends_with_ones) {
            res.push_back(i);
        }
        for (int i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}