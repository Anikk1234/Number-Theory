#include <iostream>

long long extendedGcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = extendedGcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extendedGcd(a, m, x, y);
    if (g != 1) return -1; // modular inverse does not exist
    return (x % m + m) % m;
}

int main() {
    long long a1, m1, a2, m2;
    while (std::cin >> a1 >> m1 >> a2 >> m2) {
        long long M = m1 * m2;
        long long M1 = m2;
        long long M2 = m1;
        long long M1_inv = modInverse(M1, m1);
        long long M2_inv = modInverse(M2, m2);
        long long x = (static_cast<__int128>(a1) * M1 * M1_inv + static_cast<__int128>(a2) * M2 * M2_inv) % M;
        std::cout << x << std::endl;
    }
    return 0;
}
