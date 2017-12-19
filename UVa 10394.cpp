#include <bits/stdc++.h>

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define iter(i, a, b) for(int i = (a) ; i < (b) ; i++)
#define mem(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair< int , int > pii;
typedef pair< int , pii > iii;
typedef vector< pii > vii;

#define INF (1 << 29)
#define pi (2.0 * acos(0.0))
#define MAXX 20000000

ll _sieve_size;
bitset<MAXX> bs;
vector<int> primes;
vii twinPrimes;

void sieve(ll upperbound){
    _sieve_size = upperbound + 1;

    bs.set();
    bs[0] = bs[1] = 0;

    for (ll i = 2; i <= _sieve_size; i++){
        if (bs[i]){
            for (ll j = i * i; j <= _sieve_size; j += i){
                bs[j] = 0;
            }
            primes.push_back((int)i);
        }
    }
}

void solve(){
	for(int i = 0; i < (int)primes.size() - 1; i++){
		if(primes[i + 1] - primes[i] == 2){
			twinPrimes.push_back(make_pair(primes[i], primes[i + 1]));
		}
	}
}


int main()
{
	//READ("UVa 10394.txt");
	sieve(MAXX);
	solve();
	int n;
	while(scanf("%d", &n) != EOF){
		printf("(%d, %d)\n", twinPrimes[n - 1].first, twinPrimes[n - 1].second);
	}
	return 0;
}
