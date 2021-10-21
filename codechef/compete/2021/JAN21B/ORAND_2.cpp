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
        int C = 20;
        while(C--) {
            unordered_set<int> next_set = {};
            for (int el : set) {
                for (int a : as) {
                    next_set.insert(el | a);
                }
                for (int b : bs) {
                    next_set.insert(el & b);
                }
            }
            set = next_set;
        }
        cout << set.size() << endl;
    }
    return 0;
}