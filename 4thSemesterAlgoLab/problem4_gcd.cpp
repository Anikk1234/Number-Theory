#include <iostream>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    long long A, B;
    while (std::cin >> A >> B) {
        std::cout << gcd(A, B) << std::endl;
    }
    return 0;
}
