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
#define MAXX 50000

ll _sieve_size;
bitset<MAXX> bs;
vector<int> primes;
ll L, U;

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

ll nextPrime(ll n){
	for(ll i = n + 1; i <= U; i++){
		if(isPrime(i))
			return i;
	}
	return -1;
}

int main()
{
	//READ("UVa 10140.txt");
	sieve(MAXX);
	while(scanf("%lld %lld", &L, &U) != EOF){
		ll mx = 0, mn = INF, min_x, min_y, max_x, max_y;
		ll last = nextPrime(L - 1), next;

		if(last != -1){
			while(1){
				next = nextPrime(last);

                if(next == -1)
					break;

				ll diff = next - last;

				if(diff < mn){
					mn = diff;
					min_x = last, min_y = next;
				}

                if(diff > mx){
					mx = diff;
					max_x = last, max_y = next;
                }
                last = next;
			}
		}
		if(mx == 0)
			printf("There are no adjacent primes.\n");
        else
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", min_x, min_y, max_x, max_y);
	}
	return 0;
}

