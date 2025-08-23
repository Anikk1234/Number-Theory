#include <iostream>
using namespace std;

// Extended Euclidean Algorithm that returns gcd(a, b)
// and finds integers x and y such that: a*x + b*y = gcd(a, b)
int extendedGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main()
{
    int a, b, m;
    cout << "Solving linear congruence: a*x ≡ b (mod m)" << endl;
    cout << "Enter a, b, m: ";
    cin >> a >> b >> m;

    int x, y;
    int d = extendedGCD(a, m, x, y);

    if (b % d != 0)
    {
        cout << "No solution exists because " << d << " does not divide " << b << ".\n";
        return 0;
    }

    // A particular solution:
    // Multiply x by (b/d) to get a solution for the reduced equation
    int x0 = (x * (b / d)) % m;
    // Adjust x0 to be positive modulo m
    if (x0 < 0)
        x0 += m;

    cout << "A particular solution is x = " << x0 << endl;
    cout << "General solution:" << endl;

    // There are d solutions spaced by m/d
    int step = m / d;
    for (int k = 0; k < d; ++k)
    {
        int sol = (x0 + k * step) % m;
        if (sol < 0)
            sol += m;
        cout << "x = " << sol << " (mod " << m << ")" << endl;
    }

    return 0;
}