#include <bits/stdc++.h>
using namespace std;

int eulerTotient(int n)
{
    int result = n;
    int temp = n;
    for (int p = 2; p * p <= temp; ++p)
    {
        if (temp % p == 0)
        {
            while (temp % p == 0)
                temp /= p;
            result -= result / p;
        }
    }
    if (temp > 1)
        result -= result / temp;
    return result;
}

long long modExp(long long base, int exp, int mod)
{
    long long result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main()
{
    int a, n;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter n: ";
    cin >> n;

    if (__gcd(a, n) != 1)
    {
        cout << a << " and " << n << " are not coprime." << endl;
        return 0;
    }

    int phi = eulerTotient(n);
    long long result = modExp(a, phi, n);

    cout << "phi(" << n << ") = " << phi << endl;
    cout << a << "^" << phi << " mod " << n << " = " << result
         << " (should be 1 by Euler's Theorem)" << endl;

    return 0;
}