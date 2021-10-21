#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

int CalcCost(const vector<int> &indexes) {
    int res = 0;
    int i = 0;
    int j = indexes.size() - 1;
    int true_index = 0;
    while (i <= j) {
        if (indexes[i] != true_index) {
            j--;
            res++;
        } else {
            i++;
        }
        true_index++;
    }
    return res;
}

void Print(int new_sum, int new_cost, const vector<int> &new_indexes) {
    cout << "New cost: " << new_sum << " " << new_cost << endl;
    for (int el : new_indexes) {
        cout << el << " ";
    }
    cout << endl;
}

vector<vector<int>> FindMinSubsReverse(const vector<int> &cards, const int Y) {
    int size = cards.size();
    vector<vector<int>> subs(size + 1, vector<int>(Y + 1));
    for (int i = 0; i <= size; i++) {
        subs[i][0] = 0;
    }
    for (int i = 1; i <= Y; i++) {
        subs[size][i] = 1e9;
    }
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 1; j <= Y; j++) {
            subs[i][j] = subs[i + 1][j];
            if (j >= cards[i] && subs[i + 1][j - cards[i]] != 1e9) {
                subs[i][j] = std::min(subs[i][j], subs[i + 1][j - cards[i]] + 1);
            }
        }
    }
    return subs;
}

vector<vector<int>> FindMaxSubs(const vector<int> &cards, const int Y) {
    int size = cards.size();
    vector<vector<int>> subs(size + 1, vector<int>(Y + 1));
    for (int i = 0; i <= size; i++) {
        subs[i][0] = 0;
    }
    for (int i = 1; i <= Y; i++) {
        subs[0][i] = -1;
    }
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= Y; j++) {
            subs[i][j] = subs[i - 1][j];
            if (j >= cards[i - 1] && subs[i - 1][j - cards[i - 1]] != -1) {
                subs[i][j] = std::max(subs[i][j], subs[i - 1][j - cards[i - 1]] + 1);
            }
        }
    }
    return subs;
}

int Find(const vector<int> &cards, const int X, const int Y) {
    vector<vector<int>> min_subs = FindMinSubsReverse(cards, Y);
    vector<vector<int>> max_subs = FindMaxSubs(cards, Y);

    int ans = 1e9;
    for (int partition = 0; partition < cards.size(); partition++) {
        if (partition == 0) {
            for (int sum_right = X; sum_right <= Y; sum_right++) {
                int count_right = min_subs[partition][sum_right];
                if (count_right != 1e9) {
                    ans = std::min(ans, count_right);
                }
            }
        } else {
            for (int sum_left = 0; sum_left <= Y; sum_left++) {
                int count_left = max_subs[partition][sum_left];
                if (count_left > 0) {
                    int start = std::max(0, X - sum_left);
                    int end = Y - sum_left;
                    for (int sum_right = start; sum_right <= end; sum_right++) {
                        int count_right = min_subs[partition][sum_right];
                        if (count_right != 1e9) {
                            if (count_left + count_right >= partition) {
                                ans = std::min(ans, count_right);
                            } else {
                                ans = std::min(ans, count_left + count_right);
                            }
                        }
                    }
                }
            }
        }
    }
    return ans == 1e9 ? -1 : ans;
}

int main() {
    //RunTests();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        int X = Read<int>();
        int Y = Read<int>();
        vector<int> cards;
        int sum = 0;
        while (N--) {
            int card = Read<int>();
            cards.push_back(card);
            sum += card;
        }
        if (sum < X) {
            cout << -1 << endl;
            continue;
        }
        sum = 0;
        bool found = false;
        for (int i = 0; i < cards.size(); i++) {
            sum += cards[i];
            if (sum >= X && sum <= Y) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << 0 << endl;
            continue;
        }
        auto t1 = std::chrono::high_resolution_clock::now();
        int ans = Find(cards, X, Y);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
        //cout << duration << "ms" << endl;
        //cout << "Answer: " << ans << endl;
        cout << ans << endl;
    }
    return 0;
}