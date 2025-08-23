/*
There are 
𝐾
K prison cells, each locked with a magic code. To open all cells, the guard must shout a number 
𝑋
X. A cell with lock number 
𝑎
𝑖
a
i
	​

 will only open if 
gcd
⁡
(
𝑋
,
𝑎
𝑖
)
=
1
gcd(X,a
i
	​

)=1.

The guard wants to know the smallest positive integer 
𝑋
X that opens all cells.

Input

First line: integer 
𝐾
K 
(
1
≤
𝐾
≤
2
⋅
10
5
)
(1≤K≤2⋅10
5
)

Second line: 
𝐾
K integers 
𝑎
1
,
𝑎
2
,
…
,
𝑎
𝐾
a
1
	​

,a
2
	​

,…,a
K
	​

 
(
1
≤
𝑎
𝑖
≤
10
6
)
(1≤a
i
	​

≤10
6
)

Output

Print the smallest 
𝑋
X. If no such 
𝑋
X exists, print -1.

Example

Input:
3
6 10 15

Output:
7


Explanation: gcd(7,6)=1, gcd(7,10)=1, gcd(7,15)=1 → works.

(Key math: Answer is the smallest prime not dividing any of the 
𝑎
𝑖
a
i
	​

; sieve + prime check)
*/


// Problem 4: Prison Cells
// Build with: g++ -O2 -std=gnu++17 smallest_coprime.cpp -o sc
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int K; if(!(cin>>K)) return 0;
    vector<int> a(K); int mx=1;
    for(int i=0;i<K;i++){ cin>>a[i]; mx=max(mx,a[i]); }

    // Sieve + SPF
    vector<int> spf(mx+1);
    vector<int> primes;
    for(int i=2;i<=mx;i++) if(!spf[i]){
        spf[i]=i; primes.push_back(i);
        if(1LL*i*i<=mx)
            for(long long j=1LL*i*i;j<=mx;j+=i)
                if(!spf[j]) spf[j]=i;
    }
    spf[1]=1;

    unordered_set<int> bad; bad.reserve(primes.size()*2);
    for (int x: a){
        while (x>1){
            int p=spf[x];
            bad.insert(p);
            while (x%p==0) x/=p;
        }
    }

    for (int p: primes){
        if (!bad.count(p)){
            cout << p << "\n";
            return 0;
        }
    }

    auto isPrime = [&](long long x)->bool{
        if (x<=1) return false;
        if (x<=mx) return spf[x]==x;
        for (int p: primes){
            if (1LL*p*p > x) break;
            if (x%p==0) return false;
        }
        return true;
    };

    long long x = (long long)mx + 1;
    if (x%2==0) ++x;
    while (!isPrime(x)) x += 2;
    cout << x << "\n";
    return 0;
}
