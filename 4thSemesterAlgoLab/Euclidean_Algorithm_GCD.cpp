
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

int main()
{
    int a = 48, b = 18;
    cout << "\nGCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}
