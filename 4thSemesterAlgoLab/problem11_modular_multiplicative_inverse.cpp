#include <iostream>

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (static_cast<__int128>(res) * base) % mod;
        base = (static_cast<__int128>(base) * base) % mod;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    long long a, m;
    while (std::cin >> a >> m) {
        if (gcd(a, m) != 1) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << modInverse(a, m) << std::endl;
        }
    }
    return 0;
}
