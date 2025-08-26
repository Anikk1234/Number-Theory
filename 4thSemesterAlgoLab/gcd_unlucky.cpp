#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 gcdll(int64 a, int64 b) {
    return b ? gcdll(b, a % b) : a;
}

int64 lcmll(int64 a, int64 b) {
    return a / gcdll(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int64> p(n), s(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) cin >> s[i];

        // Step 3: construct candidate array
        vector<int64> a(n);
        for (int i = 0; i < n; i++)
            a[i] = lcmll(p[i], s[i]);

        // check prefix GCD
        bool ok = true;
        int64 g = 0;
        for (int i = 0; i < n; i++) {
            g = gcdll(g, a[i]);
            if (g != p[i]) {
                ok = false;
                break;
            }
        }

        // check suffix GCD
        if (ok) {
            g = 0;
            for (int i = n - 1; i >= 0; i--) {
                g = gcdll(g, a[i]);
                if (g != s[i]) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
