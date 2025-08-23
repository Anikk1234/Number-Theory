#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    // Step 1: a is bigger
    if (b > a)
    {
        swap(a, b);
    }

    while (b != 0)
    {
        int r = a % b; // Step 2: find remainder
        a = b;         // Step 4: update a
        b = r;         // Step 4: update b
    }
    return a; // GCD is stored in a
}

// GCD * LCM = A*B
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b; // Compute LCM using GCD
}

int main()
{
    int a = 12, b = 15;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << "\n";
    cout << "LCM(" << a << ", " << b << ") = " << lcm(a, b) << "\n";
    return 0;
}