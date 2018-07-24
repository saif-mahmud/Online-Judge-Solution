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
#define MAXX 1000010

ll _sieve_size;
bitset<MAXX> bs;
vector<int> primes;

ll modifiedNumDiffPF[MAXX];

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

void modifiedSieve(){
	mem(modifiedNumDiffPF, 0);

	for(int i = 2; i < MAXX; i++){
		if(modifiedNumDiffPF[i] == 0){
			for(int j = i; j < MAXX; j += i){
				modifiedNumDiffPF[j]++;
			}
		}
	}
}

vi primeFactors(ll N){ //N = a^i X b^j X ... X c^k
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

vii primePowFactors(ll N){
	vii powFactors;
	ll PF_idx = 0, PF = primes[PF_idx];

	while(PF * PF <= N){
		ll power = 0;

		while(N % PF == 0){
			N /= PF;
			power++;
		}

		if(power > 0)
			powFactors.push_back(make_pair(PF, power));

		PF = primes[++PF_idx];
	}

    if(N != 1)
		powFactors.push_back(make_pair(N, 1));

	return powFactors;
}

ll numPF(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = 0;

	while(PF * PF <= N){
		while(N % PF == 0){
			N /= PF;
			ans++;
		}
		PF = primes[++PF_idx];
	}

	if(N != 1)
		ans++;

	return ans;
}

ll numDiffPF(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = 0;

	while(PF * PF <= N){
		if(N % PF == 0)
			ans++;

		while(N % PF == 0)
			N /= PF;

		PF = primes[++PF_idx];
	}

	if(N != 1)
		ans++;

	return ans;
}

ll sumPF(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = 0;

	while(PF * PF <= N){
		while(N % PF == 0){
            N /= PF;
            ans += PF;
		}
		PF = primes[++PF_idx];
	}

	if(N != 1)
		ans += N;

	return ans;
}

ll numDiv(ll N){ //numDiv(N) = (i + 1) X (j + 1) X ... X (k + 1)
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1;

	while(PF * PF <= N){
		ll power = 0;

		while(N % PF == 0){
			N /= PF;
			power++;
		}

		ans *= (power + 1);
		PF = primes[++PF_idx];
	}

    if(N != 1)
		ans *= 2;

	return ans;
}

ll sumDiv(ll N){ //sumDiv(N) = ( (a^(i + 1) - 1 ) / (a - 1) ) X ( (b^(j + 1) - 1 ) / (b - 1) ) X ... X ( (c^(k + 1) - 1 ) / (c - 1) )
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;

    while(PF * PF <= N){
		ll power = 0;

		while(N % PF == 0){
			N /= PF;
			power++;
		}

		ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
		PF = primes[++PF_idx];
    }

    if(N != 1)
		ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);

	return ans;
}

ll EulerPhi(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = N;

	while(PF * PF <= N){
		if(N % PF == 0)
			ans -= ans / PF;

		while(N % PF == 0)
			N /= PF;

		PF = primes[++PF_idx];
	}

	if(N != 1)
		ans -= ans / N;

	return ans;
}

int main(){
	//READ("inp.txt");

	modifiedSieve();

	ll n;

	while(1){
		scanf("%lld", &n);

		if(n == 0)
			break;

		printf("%lld : %lld\n", n, modifiedNumDiffPF[n]);
	}

	return 0;
}

