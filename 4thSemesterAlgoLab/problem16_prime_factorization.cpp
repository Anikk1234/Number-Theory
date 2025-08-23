#include <iostream>
#include <vector>

void primeFactorization(long long n) {
    std::vector<long long> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }
    for (long long i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
    for (size_t i = 0; i < factors.size(); ++i) {
        std::cout << factors[i] << (i == factors.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    long long n;
    while (std::cin >> n) {
        primeFactorization(n);
    }
    return 0;
}
