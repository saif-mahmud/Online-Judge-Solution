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

#define INF 1000000000
#define pi (2.0 * acos(0.0))
#define MAXX 1000

ll coin[] = {50, 25, 10, 5, 1};
ll dp[6][30005];
ll make;

ll coinChange(ll idx, ll amount){
	if(idx > 4)
		return 0;
	if(amount == 0)
		return 1;
	if(amount < 0)
		return 0;

	if(dp[idx][amount] != -1)
		return dp[idx][amount];

	dp[idx][amount] = coinChange(idx + 1, amount) + coinChange(idx, amount - coin[idx]);

	return dp[idx][amount];
}

int main(){
	//READ("UVa 357.txt");
	mem(dp, -1);

	while(scanf("%lld", &make) != EOF){
		ll ans = coinChange(0, make);
		if(ans != 1)
			printf("There are %lld ways to produce %lld cents change.\n", ans, make);
		else
			printf("There is only 1 way to produce %lld cents change.\n", make);
	}

	return 0;
}
