#include <iostream>
#include <vector>
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

struct Result {
    int count;
    vector<int> indexes;
};

vector<vector<bool>> FindSubs(const vector<int> &cards, const int Y) {
    int size = cards.size();
    vector<vector<bool>> subs(size + 1, vector<bool>(Y + 1));
    for (int i = 0; i <= size; i++) {
        subs[i][0] = true;
    }
    for (int i = 1; i <= Y; i++) {
        subs[0][i] = false;
    }

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= Y; j++) {
            subs[i][j] = subs[i - 1][j];
            if (j >= cards[i - 1]) {
                subs[i][j] = subs[i][j] || subs[i - 1][j - cards[i - 1]];
            }
        }
    }
    return subs;
}

int FindMinSumMoreThan(const vector<int> &heights, const int lo, const int hi) {
    vector<vector<bool>> subs = FindSubs(heights, hi);
    for (int k = lo; k <= hi; k++) {
        if (subs[heights.size()][k]) {
            return k;
        }
    }
    return -1;
}

int FindSimple(const vector<int>& heights, const int K) {
    int running_sum = 0;
    int count = 1;
    for (int i = heights.size() - 2; i >= 0; i--) {
        running_sum += heights[i];
        count++;
        if (running_sum >= K) {
            return count;
        }
    }
    return -1;
}

int FindComplex(const vector<int>& heights, const int K) {
    int running_sum = 0;
    int count = 0;
    for (int i = heights.size() - 1; i >= 0; i--) {
        count++;
        running_sum += heights[i];
        if (running_sum >= 2 * K) {
            int sum = FindMinSumMoreThan(vector<int>(heights.begin() + i, heights.end()), K, 2*K);
            if (sum != -1 && (running_sum - sum) >= K) {
                return count;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        int K = Read<int>();
        vector<int> heights;
        while (N--) {
            heights.push_back(Read<int>());
        }
        sort(heights.begin(), heights.end());
        int ans;
        if (heights.back() >= K) {
            ans = FindSimple(heights, K);
        } else {
            ans = FindComplex(heights, K);
        }
        cout << ans << endl;
    }
    return 0;
}