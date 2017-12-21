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
#define MAXX 10000005

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

void Goldbach(int n){
	bool flag = false;
	int a, b;

	for(int i = 0; i < (int)primes.size(); i++){
		a = n - primes[i];

		if(bs[a] == 1){
			b = primes[i];
			flag = true;
			break;
		}
	}

	if(flag)
		printf("%d %d\n", b, a);
}

int main()
{
	//READ("UVa 10168.txt");
	//WRITE("Output.txt");
	sieve(MAXX);
	int n;
	while(scanf("%d", &n) != EOF){
		if(n < 8){
			printf("Impossible.\n");
		}
		else if(n % 2 == 0){
			printf("2 2 ");
			Goldbach(n - 4);
		}
		else if(n % 2 == 1){
			printf("2 3 ");
			Goldbach(n - 5);
		}
	}
	return 0;
}

