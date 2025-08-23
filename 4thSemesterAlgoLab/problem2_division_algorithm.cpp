#include <iostream>

int main() {
    long long N, d;
    while (std::cin >> N >> d) {
        if (d != 0) {
            long long q = N / d;
            long long r = N % d;
            if (r < 0) {
                r += d;
                q--;
            }
            std::cout << q << " " << r << std::endl;
        }
    }
    return 0;
}
