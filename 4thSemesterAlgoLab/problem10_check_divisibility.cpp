#include <iostream>

int main() {
    long long A, B;
    while (std::cin >> A >> B) {
        if (B != 0) {
            if (A % B == 0) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    return 0;
}
