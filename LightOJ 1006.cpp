#include <bits/stdc++.h>

using namespace std;

long long a, b, c, d, e, f;
long long dp[10005];

long long fn(long long n){
    if(n == 0) return a;
    if(n == 1) return b;
    if(n == 2) return c;
    if(n == 3) return d;
    if(n == 4) return e;
    if(n == 5) return f;

    if(dp[n] != -1){
        return dp[n];
    }

    else{
        dp[n] = fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ;
        dp[n] = dp[n] % 10000007;
        return dp[n];
    }
}

int main(){
    //freopen("LightOJ 1006.txt", "r", stdin);
    //freopen("LightOJ 1006_Output.txt", "w", stdout);
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while(cases--) {
        for(int i = 0; i < 10005; i++)
            dp[i] = -1;
        scanf("%lld %lld %lld %lld %lld %lld %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
