#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isPrime(int p)
{
    if (p < 2)
        return false;
    for (int i = 2; i <= sqrt(p); ++i)
    {
        if (p % i == 0)
            return false;
    }
    return true;
}

// Fast Modular Exponentiation Function
int modExp(int a, int b, int mod)
{
    int result = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
        {
            result = (int)(((long long)result * a) % mod);
        }
        a = (int)(((long long)a * a) % mod);
        b >>= 1;
    }
    return result;
}

// Function to compute gcd
int gcd(int a, int b)
{
    while (b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int a, b, p;
    cout << "Enter base a, exponent b, and prime p: ";
    cin >> a >> b >> p;

    // Check if p is prime
    if (!isPrime(p))
    {
        cout << "Error: p must be a prime number." << endl;
        return 1;
    }

    // Check if a and p are coprime
    if (gcd(a, p) != 1)
    {
        cout << "Error: a and p are not coprime. Fermat's Little Theorem cannot be applied." << endl;
        return 1;
    }

    // Using Fermat's Little Theorem:
    // a^(p-1) ≡ 1 (mod p)
    // So, a^b mod p = a^(b mod (p-1)) mod p
    int reducedExponent = b % (p - 1);
    int result = modExp(a, reducedExponent, p);

    cout << a << "^" << b << " mod " << p << " = " << result << endl;
    return 0;
}