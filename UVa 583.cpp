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
typedef vector<int> vi;
typedef vector< pii > vii;
typedef map<int, int> mii;

#define INF (1 << 29)
#define PI (2.0 * acos(0.0))
#define MAXX 1000000

ll _sieve_size;
bitset<MAXX> bs;
vector<int> primes;

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

vi primeFactors(ll N){
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];

	while(PF * PF <= N){
		while(N % PF == 0){
			N /= PF;
			factors.push_back(PF);
		}
		PF = primes[++PF_idx];
	}
	if(N != 1)
		factors.push_back(N);
	return factors;
}

int main(){
	//READ("UVa 583.txt");
	sieve(MAXX);
	ll g;
	while(1){
		scanf("%lld", &g);

		if(g == 0)
			break;
		if(g > 0){
			vi r = primeFactors(g);
			printf("%lld = %d", g, r[0]);
			for(int i = 1; i < (int)r.size(); i++){
				printf(" x %d", r[i]);
			}
			printf("\n");
		}
		if(g < 0){
			g = abs(g);
			vi r = primeFactors(g);
			printf("-%lld = -1 x %d", g, r[0]);
			for(int i = 1; i < (int)r.size(); i++){
				printf(" x %d", r[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
