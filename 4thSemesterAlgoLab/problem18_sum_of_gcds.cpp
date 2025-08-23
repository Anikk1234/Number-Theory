#include <iostream>
#include <vector>

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

int main() {
    long long n;
    while (std::cin >> n) {
        long long sum_gcd = 0;
        for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                sum_gcd += i * phi(n / i);
                if (i * i != n) {
                    sum_gcd += (n / i) * phi(i);
                }
            }
        }
        std::cout << sum_gcd << std::endl;
    }
    return 0;
}
