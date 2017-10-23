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

#define MAX_N 1005
#define MAX_W 35

int dp[MAX_N][MAX_W];
int weight[MAX_N], val[MAX_N];
int n;

int knapSack(int idx, int remW){
	if(idx == n || remW == 0)
		return 0;

	if(dp[idx][remW] != -1)
		return dp[idx][remW];

	if(weight[idx] > remW)
		return dp[idx][remW] = knapSack(idx + 1, remW);

	return dp[idx][remW] = max(knapSack(idx + 1, remW), val[idx] + knapSack(idx + 1, remW - weight[idx]));
}

int main(){
	//READ("UVa 10130.txt");

	int tc, case_no = 0;
	scanf("%d", &tc);

	while(tc--){
		mem(dp, -1);

		scanf("%d", &n);

		rep(i, n)
			scanf("%d %d", &val[i], &weight[i]);

		int G, maxW, ans = 0;
		scanf("%d", &G);

		while(G--){
			scanf("%d", &maxW);
			ans += knapSack(0, maxW);
		}

		printf("%d\n", ans);
	}

	return 0;
}
