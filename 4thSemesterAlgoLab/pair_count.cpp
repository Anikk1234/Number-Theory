#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 modmul(int64 a, int64 b, int64 mod) {
    return ( (__int128)a * b ) % mod;
}

int64 modpow(int64 a, long long e, int64 mod) {
    int64 res = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1) res = modmul(res, a, mod);
        a = modmul(a, a, mod);
        e >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int64 p, k;
    if (!(cin >> n >> p >> k)) return 0;

    vector<int64> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // b[i] = a[i]^3 mod p
    for (int i = 0; i < n; ++i) b[i] = modpow(a[i], 3, p);

    long long ans = 0;

    if (k == 0) {
        long long zeros = 0;
        for (auto x : b) if (x == 0) ++zeros;
    
        ans = zeros * (long long)(n - zeros) + (zeros * (zeros - 1) / 2);
    } else {
        unordered_map<int64, long long> freq;
        freq.reserve(n * 2);
        for (int i = 0; i < n; ++i) {
            int64 bi = b[i];
            if (bi == 0) {
                freq[bi]++;
                continue;
            }
            int64 inv_bi = modpow(bi, p - 2, p); // p is prime
            int64 target = modmul(k, inv_bi, p);
            auto it = freq.find(target);
            if (it != freq.end()) ans += it->second;
            freq[bi]++;
        }
    }

    cout << ans << "\n";
    return 0;
}
