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

int coin[] = {50, 25, 10, 5, 1};
int dp[6][30005];
int make;

int coinChange(int idx, int amount){
	if(idx >= 5){
		if(amount == 0)
			return 1;
		else
			return 0;
	}

	if(dp[idx][amount] != -1)
		return dp[idx][amount];

	int ret_1 = 0, ret_2 = 0;

	if(amount - coin[idx] >= 0)
		ret_1 = coinChange(idx, amount - coin[idx]);

	ret_2 = coinChange(idx + 1, amount);

	return dp[idx][amount] = ret_1 + ret_2;
}

int main(){
	//READ(".txt");
	mem(dp, -1);

	while(scanf("%d", &make) != EOF){
		int ans = coinChange(0, make);
		if(ans != 1)
			printf("There are %d ways to produce %d cents change.\n", ans, make);
		else
			printf("There is only 1 way to produce %d cents change.\n", make);
	}

	return 0;
}
