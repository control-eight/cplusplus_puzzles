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

    int calc(string answerKey, int k, char t) {
        int res = 0;
        int r = 0;
        int lo = 0;
        for (int i = 0; i < answerKey.size(); i++) {
            char c = answerKey[i];
            if (c != t) {
                if (k > 0) {
                    k--;
                } else {
                    while (answerKey[lo] != (t == 'T'? 'F': 'T')) {
                        lo++;
                        r--;
                    }
                    lo++;
                    r--;
                }
            }
            r++;
            res = std::max(res, r);
        }
        return res;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return std::max(calc(answerKey, k, 'T'), calc(answerKey, k, 'F'));
    }
};

int main() {
    Solution s;
    cout << s.maxConsecutiveAnswers("TTFF", 2) << endl;
    cout << s.maxConsecutiveAnswers("TFFT", 1) << endl;
    cout << s.maxConsecutiveAnswers("TTFTTFTT", 1) << endl;
    cout << s.maxConsecutiveAnswers("FFFTTFTTFT", 3) << endl;
    // 85
    cout << s.maxConsecutiveAnswers("FTFFTFTFTTFTTFTTFFTTFFTTTTTFTTTFTFFTTFFFFFTTTTFTTTTTTTTTFTTFFTTFTFFTTTFFFFFTTTFFTTTTFTFTFFTTFTTTTTTF", 32) << endl;
    return 0;
}
// FTFFTFTFTTFTTFTTFFTTFFTTTTTFTTTFTFFTTFFFFFTTTTFTTTTTTTTTFTTFFTTFTFFTTTFFFFFTTTFFTTTTFTFTFFTTFTTTTTTF