#include <iostream>

int main() {
    long long A, B;
    while (std::cin >> A >> B) {
        if (B != 0) {
            long long quotient = A / B;
            long long remainder = A % B;
            std::cout << quotient << " " << remainder << std::endl;
        }
    }
    return 0;
}
