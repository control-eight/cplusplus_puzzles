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

vector<bool> calc(lli k, lli N, int i, vector<bool>& result) {
    if (k == 0) {
        return result;
    }
    if (k % 2 == 0 || std::pow(2, i) > N) {
        return {};
    }
    if ((k - 1) % 2 == 0) {
        vector<bool> r1 = result;
        r1.push_back(true);
        vector<bool> l1 = calc((k - 1) / 2, N, i + 1, r1);
        if (!l1.empty()) {
            return l1;
        }
    }
    if ((k + 1) % 2 == 0) {
        result.push_back(false);
        return calc((k + 1) / 2, N, i + 1, result);
    }
    return {};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        lli N = Read<lli>();
        lli K = Read<lli>();
        if (K == 0) {
            cout << "YES" << endl;
            cout << "0" << endl;
            continue;
        }
        vector<bool> init = {};
        vector<bool> result = calc(K, N, 0, init);
        if (result.empty()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << result.size() << endl;
            int pos = K;
            int i = 0;
            for (bool r : result) {
                if (r) {
                    pos -= std::pow(2, i) - 1;
                    cout << pos << endl;
                    pos--;
                } else {
                    pos++;
                    cout << pos << endl;
                    pos += std::pow(2, i) - 1;
                }
                i++;
            }
        }
    }
    return 0;
}