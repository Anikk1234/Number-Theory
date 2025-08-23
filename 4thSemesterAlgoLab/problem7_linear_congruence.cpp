#include <iostream>
using namespace std;
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solveLinearCongruence(long long a, long long b, long long m) {
    long long g = gcd(a, m);
    if (b % g != 0) {
        cout << -1 << std::endl;
        return;
    }
    long long a_inv = modInverse(a / g, m / g);
    long long x0 = (b / g * a_inv) % (m/g);
    if (x0 < 0) x0 += (m/g);
    cout << x0 << endl;
}

int main() {
    long long a, b, m;
    while (cin >> a >> b >> m) {
        solveLinearCongruence(a, b, m);
    }
    return 0;
}
