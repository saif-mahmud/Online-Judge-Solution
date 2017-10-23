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

int a[55], c[55];
int n, k;
ll dp[55][1005];

ll coinChange(int idx, int sum){
	ll ans = 0;

	if(sum == k)
		return 1;
	if(idx == n)
		return 0;

	if(dp[idx][sum] != -1)
		return dp[idx][sum];

	for(int i = 0; i <= c[idx] && (sum + (i * a[idx])) <= k; i++){
		ans += coinChange(idx + 1, sum + (i * a[idx]));
		ans = ans % 100000007;
	}

	return dp[idx][sum] = ans;
}

int main(){
	//READ("LightOJ 1231.txt");

	int tc, case_no = 0;
	scanf("%d", &tc);

	while(tc--){
		scanf("%d %d", &n, &k);

		rep(i, n)
			scanf("%d", &a[i]);
		rep(i, n)
			scanf("%d", &c[i]);

		mem(dp, -1);

		printf("Case %d: %d\n", ++case_no, coinChange(0, 0));
	}

	return 0;
}
