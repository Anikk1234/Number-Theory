#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    long long n;
    while (std::cin >> n) {
        std::vector<long long> divisors;
        for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }
        std::sort(divisors.begin(), divisors.end());
        for (size_t i = 0; i < divisors.size(); ++i) {
            std::cout << divisors[i] << (i == divisors.size() - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}
