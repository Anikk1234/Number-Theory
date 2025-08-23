#include <iostream>

long long phi(long long n) {
    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

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

int main() {
    long long a, n;
    while (std::cin >> a >> n) {
        long long totient = phi(n);
        std::cout << power(a, totient, n) << std::endl;
    }
    return 0;
}
