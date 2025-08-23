/*
A space elevator requires a password — a number 
𝑃
P.
The rules say:

𝑃
P must be divisible by all integers from 1 to N.

𝑃
P must be the smallest such number.

Your task is to compute this 
𝑃
P, modulo 
10
9
+
7
10
9
+7.

Input

A single integer 
𝑁
N 
(
1
≤
𝑁
≤
10
6
)
(1≤N≤10
6
)

Output

The password 
𝑃
(
m
o
d
10
9
+
7
)
P(mod10
9
+7).

Example

Input:
10

Output:
2520
*/


#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

long long modpow(long long a, long long e){
    long long r=1%MOD;
    while(e){
        if(e&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; 
    if(!(cin>>N)) return 0;

    vector<bool> is(N+1,true);
    is[0]=is[1]=false;
    vector<int> primes;
    for (int i=2;i<=N;i++){
        if(is[i]){
            primes.push_back(i);
            if(1LL*i*i<=N)
                for(long long j=1LL*i*i;j<=N;j+=i) is[j]=false;
        }
    }
    long long ans=1;
    for (int p: primes){
        long long pe = p;
        while (pe * p <= N) pe *= p;
        ans = (ans * (pe % MOD)) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
