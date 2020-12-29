#include <iostream>
#include <vector>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

bool FindOdd(std::vector<int>& freq) {
    for (int i = 0; i < freq.size(); i++) {
        if (freq[i] % 2 != 0) {
            freq[i]--;
            return true;
        }
    }
    return false;
}

bool FindAny(std::vector<int>& freq) {
    for (int i = 0; i < freq.size(); i++) {
        if (freq[i] > 0) {
            freq[i]--;
            return true;
        }
    }
    return false;
}

bool FindPalindrom(std::vector<int>& freq) {
    for (int i = 0; i < freq.size(); i++) {
        if (freq[i] >= 2) {
            freq[i] -= 2;
            if (FindOdd(freq)) {
                return true;
            } else {
                return FindAny(freq);
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        string S = Read<string>();
        std::vector<int> freq(26, 0);
        for (char c : S) {
            freq[c - 'a']++;
        }
        int ans = 0;
        while (FindPalindrom(freq)) {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}