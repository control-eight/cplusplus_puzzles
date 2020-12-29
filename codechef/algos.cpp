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