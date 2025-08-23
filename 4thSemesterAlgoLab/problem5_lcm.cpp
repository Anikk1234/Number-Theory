#include <iostream>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return std::abs(a * b) / gcd(a, b);
}

int main() {
    long long A, B;
    while (std::cin >> A >> B) {
        std::cout << lcm(A, B) << std::endl;
    }
    return 0;
}
