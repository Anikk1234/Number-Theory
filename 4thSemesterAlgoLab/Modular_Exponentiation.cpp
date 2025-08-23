#include <bits/stdc++.h>
using namespace std;

int Power(int A, int B, int P)
{
    int Result = 1;
    while (B)
    {
        if (B % 2)
        {
            Result = (Result * A) % P;
            B--;
        }
        else
        {
            A = (A * A) % P;
            B /= 2;
        }
    }
    return Result;
}

int main()
{
    // A^B % P
    cout << Power(13, 13, 143) << endl;
    return 0;
}