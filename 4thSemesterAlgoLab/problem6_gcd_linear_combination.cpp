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

int main() {
    long long A, B;
    while (std::cin >> A >> B) {
        long long x, y;
        extendedGcd(A, B, x, y);
        std::cout << x << " " << y << std::endl;
    }
    return 0;
}
