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
#define MAXX 1000

ll solve(ll n, ll m, ll k){
	if(k > n || k > m)
		return 0;
	else if(k == 0)
		return 1;
	else if(m == 1)
		return n;
	else
		return n * solve(n - 1, m - 1, k - 1) + solve(n, m - 1, k);
}


int main(){
	//READ(".txt");

	int tc, case_no = 0;
	scanf("%d", &tc);

	while(tc--){
		ll n, k;
		scanf("%lld %lld", &n, &k);

		printf("Case %d: %lld\n", ++case_no, solve(n, n, k));
	}

	return 0;
}
