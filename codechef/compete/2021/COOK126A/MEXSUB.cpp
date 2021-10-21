#include <iostream>
#include <vector>
#include <unordered_set>

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
        std::vector<int> v;
        while (N--) {
            v.push_back(Read<int>());
        }
        int smallest_missing = 0;
        unordered_set<int> s(v.begin(), v.end());
        for (int i = 0; i <= v.size(); i++) {
            if (s.insert(i).second) {
                smallest_missing = i;
                break;
            }
        }
        //cout << "Smallest: " << smallest_missing << endl;
        unordered_set<int> s222;
        int right_limit = v.size() - 1;
        for (int j = v.size() - 1; j >= 0; j--) {
            if (v[j] < smallest_missing) {
                s222.insert(v[j]);
            }
            if (s222.size() == smallest_missing || s222.size() == s.size()) {
                right_limit = j;
                break;
            }
        }
        lli modulo = 1e9 + 7;
        lli ans = 0;
        int running_mex_count = 0;
        unordered_set<int> s1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] < smallest_missing) {
                s1.insert(v[i]);
            }
            if (s1.size() == smallest_missing || s1.size() == s.size()) {
                running_mex_count++;
                s1.clear();
            }
            if (i < right_limit) {
                ans += running_mex_count;
                ans %= modulo;
            }
        }
        //cout << "rc " << running_mex_count << endl;
        cout << ans << endl;
    }
    return 0;
}