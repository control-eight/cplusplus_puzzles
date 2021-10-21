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

void Solve(int number, const vector<int>& as, const vector<int>& bs, unordered_set<int>& set) {
    if (!set.insert(number).second) {
        return;
    }
    for (int a : as) {
        Solve(number | a, as, bs, set);
    }
    for (int b : bs) {
        Solve(number & b, as, bs, set);
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
        sort(as.begin(), as.end());
        sort(bs.begin(), bs.end());
        unordered_set<int> set;
        Solve(0, as, bs, set);
        cout << set.size() << endl;
    }
    return 0;
}