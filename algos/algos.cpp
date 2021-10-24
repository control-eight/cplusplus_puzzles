// Check if number is prime
bool IsPrime(int n) {
    if (n <= 1) return false;
    if (n % 2 == 0) return true;

    int boundary = sqrt(n);
    for (int i = 3; i <= boundary; i++) {
        if (n % i == 0) {
            return true;
        }
    }
    return false;
}

// Greatest common denominator
int Gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

// Greatest common denominator vector
int GcdVector(vector<int> v) {
    int ans = v[0];
    for (int i = 1; i < v.size(); i++) {
        ans = gcd(v[i], ans);
    }
    return ans;
}

// Lowest prime factor / lowest prime divisor
int Lpf(int n) {
    int res;
    while (n % 2 == 0) {
        res = 2;
        n >>= 1;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            res = i;
            n /= i;
        }
    }
    if (n > 2) {
        res = n;
    }
    return res;
}

// Check if number is palindromic
bool IsPalindromic(int n) {
    std::string str = std::to_string(n);
    int i = 0;
    int j = str.size() - 1;
    while (i != j) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

// Multiplicative inverse
int ModInverse(lli a, lli m) {
    lli m0 = m;
    lli y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        lli q = a / m;
        lli t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;

    return x;
}

// binary search
pair<int, lli> FindLessOrEqual(const vector<lli>& v, lli el) {
    auto iter = lower_bound(v.begin(), v.end(), el);
    if (iter == v.end()) {
        iter--;
    }
    if (*iter <= el) {
        return {iter - v.begin(), *iter};
    }
    if (iter != v.begin()) {
        iter--;
        return {iter - v.begin(), *iter};
    }
    return {-1, *iter};
}

pair<int, lli> FindLessOrEqual2(const vector<lli>& v, lli el) {
    auto iter = lower_bound(v.begin(), v.end(), el);
    // exact match.
    if (iter != v.end() && *iter == el) {
        return {iter - v.begin(), *iter};
    }
    // not found.
    if (iter == v.begin()) {
        return {-1, *iter};
    }
    // return smaller.
    iter--;
    return {iter - v.begin(), *iter};
}

// binary search
pair<int, lli> FindGreaterOrEqual(const vector<lli>& v, lli el) {
    auto iter = lower_bound(v.begin(), v.end(), el);
    if (*iter >= el) {
        return {iter - v.begin(), *iter};
    }
    return {-1, *iter};
}

// Find sum subsets
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

// Find sum subsets
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

// Find sum subsets
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

// Find sum subsets
vector<vector<int>> FindMinSubs(const vector<int> &cards, const int Y) {
    int size = cards.size();
    vector<vector<int>> subs(size + 1, vector<int>(Y + 1));
    for (int i = 0; i <= size; i++) {
        subs[i][0] = 0;
    }
    for (int i = 1; i <= Y; i++) {
        subs[0][i] = 1e9;
    }
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= Y; j++) {
            subs[i][j] = subs[i - 1][j];
            if (j >= cards[i - 1] && subs[i - 1][j - cards[i - 1]] != 1e9) {
                subs[i][j] = std::min(subs[i][j], subs[i - 1][j - cards[i - 1]] + 1);
            }
        }
    }
    return subs;
}

lli closest(lli v1, lli v2, lli target) {
    if (target - v1 >= v2 - target) {
        return v2;
    } else {
        return v1;
    }
}

int findClosest(const vector<lli>& v, lli lo, lli hi, lli target) {
    if (target <= v[lo]) {
        return v[lo];
    }
    if (target >= v[hi - 1]) {
        return v[hi - 1];
    }
    lli mid = 0;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (v[mid] == target) {
            return v[mid];
        }
        if (target < v[mid]) {
            if (mid > 0 && target > v[mid - 1]) {
                return closest(v[mid - 1], v[mid], target);
            }
            hi = mid;
        } else {
            if (mid < hi - 1 && target < v[mid + 1]) {
                return closest(v[mid], v[mid + 1], target);
            }
            lo = mid + 1;
        }
    }
    return v[mid];
}