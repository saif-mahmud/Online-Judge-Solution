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
#define MAXX (1 << 15)

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

bool isPrime(ll N){
	if(N <= _sieve_size)
		return bs[N];
	for(int i = 0; i < (int)primes.size(); i++){
		if(N % primes[i] == 0)
			return false;
	}
	return true;
}

void Goldbach_II(int n){
	int a, b, cnt = 0;

	for(int i = 0; i < (int)primes.size(); i++){
		if(primes[i] > (n / 2))
			break;

		a = n - primes[i];

		if(bs[a] == 1)
			cnt++;
	}

	printf("%d\n", cnt);
}

int main()
{
	//READ("UVa 686.txt");
	int n;
	sieve(MAXX);
	while(scanf("%d", &n) == 1){
		if(n == 0)
			break;
		Goldbach_II(n);
	}
	return 0;
}

