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

class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.length() <= 2) return 0;
        int res = 0;
        for (int i = 0; i < s.length() - 2; i++) {
            unordered_set<char> ss;
            for (int j = i; j < i + 3; j++) {
                ss.insert(s[j]);
            }
            if (ss.size() == 3) {
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.countGoodSubstrings("xyzzaz") << "\n";
    return 0;
}