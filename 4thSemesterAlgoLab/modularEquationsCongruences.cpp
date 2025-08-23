/*Consider the infinite sequence of integers: 1, 1, 2, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 4, 5.... The sequence is built in the following way: at first the number 1 is written out, then the numbers from 1 to 2, then the numbers from 1 to 3, then the numbers from 1 to 4 and so on. Note that the sequence contains numbers, not digits. For example number 10 first appears in the sequence in position 55 (the elements are numerated from one).

Find the number on the n-th position of the sequence.

Input
The only line contains integer n (1 ≤ n ≤ 1014) — the position of the number to find.

Note that the given number is too large, so you should use 64-bit integer type to store it. In C++ you can use the long long integer type and in Java you can use long integer type.

Output
Print the element in the n-th position of the sequence (the elements are numerated from one).

Examples
InputCopy
3
OutputCopy
2
InputCopy
5
OutputCopy
2
InputCopy
10
OutputCopy
4
InputCopy
55
OutputCopy
10
InputCopy
56
OutputCopy
1

*/


#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second
 
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
 
const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
 
li n;
 
inline bool read() {
    return !!(cin >> n);
}
 
inline void solve() {
    n--;
    for (li i = 1; i <= n; i++) {
        n -= i;
    }
    cout << n + 1 << endl;
}
 
int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
 
    while (read()) {
        solve();
        //break;
    }
    
    return 0;
}
