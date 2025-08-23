#include <bits/stdc++.h>
using namespace std;

/*
 * Time Complexity ---> O(N)
 * Just cout << is_Prime[Number_You_Want_To_Check] << endl;
 */
const int MX = 1e7;
bitset<MX> is_Prime;
vector<int> Primes;
void Sieve(int N)
{
    is_Prime[2] = true;
    for (int i = 3; i <= N; i += 2)
    {
        is_Prime[i] = true;
    }
    int ITR = sqrt(N);
    for (int i = 3; i <= ITR; i += 2)
    {
        if (is_Prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                is_Prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MX; i++)
    {
        if (is_Prime[i])
        {
            Primes.push_back(i);
        }
    }
}
vector<int> prime_Factors(int n)
{
    vector<int> Factors;
    for (auto P : Primes)
    {
        if (P * P > n)
        {
            break;
        }
        while (n % P == 0)
        {
            Factors.push_back(P);
            n /= P;
        }
    }
    if (n > 1)
    {
        Factors.push_back(n);
    }
    return Factors;
}
int main()
{
    Sieve(1e7);
    int n;
    cin >> n;
    auto Factors = prime_Factors(n);
    for (auto i : Factors)
    {
        cout << i << " ";
    }
    return 0;
}