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

int main() {
    long long a, b, m;
    while (std::cin >> a >> b >> m) {
        std::cout << power(a, b, m) << std::endl;
    }
    return 0;
}
