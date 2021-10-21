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
        int N = Read<int>();
        vector<pair<int, int>> els;
        for (int i = 0; i < N; i++) {
            els.push_back({Read<int>(), i});
        }
        sort(els.begin(), els.end());

        vector<int> res(N);
        int c = 0;
        int last = -1;
        for (auto& p : els) {
            res[p.second] = p.first + c;
            if ((p.first + c) % p.first > last) {
                last = (p.first + c) % p.first;
                c++;
            }
        }
        for (int el : res) {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}