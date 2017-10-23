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
#define MAXX 11

int a[MAXX], dp[MAXX][MAXX];
int M, N;//M = # of elements in set | N = # of digits

int solve(int n, int m){//m : set element # | n : digit #
	if(n == 1)
		return 1;

	if(dp[n][m] == -1){
		int total = 0;
		iter(i, 1, M + 1){
			if(abs(a[m] - a[i]) <= 2)
				total += solve(n - 1, i);
		}
		dp[n][m] = total;
	}
	return dp[n][m];
}

int main(){
	//READ("LightOJ 1122.txt");

	int tc, case_no = 0;
	scanf("%d", &tc);

	while(tc--){
		mem(dp, -1);
		mem(a, 0);

		scanf("%d %d", &M, &N);

		iter(i, 1, M + 1)
			scanf("%d", &a[i]);

		int res = 0;

		iter(i, 1, M + 1)
			res += solve(N, i);

		printf("Case %d: %d\n", ++case_no, res);
	}

	return 0;
}
