#include <iostream>
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

class Solution {
public:
    string replaceDigits(string s) {
        string result;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                result += s[i];
            } else {
                result += s[i - 1] + s[i] - '0';
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.replaceDigits("a1b2c3d4e");
    return 0;
}