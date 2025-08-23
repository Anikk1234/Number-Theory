#include <iostream>

int main() {
    long long A, M;
    while (std::cin >> A >> M) {
        if (M != 0) {
            long long result = A % M;
            if (result < 0) {
                result += M;
            }
            std::cout << result << std::endl;
        }
    }
    return 0;
}
