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
#define MAXX 105

int grid[2 * MAXX][MAXX];
int n;
int dp[2 * MAXX][MAXX];

int rockClimbing(int i, int j){
	if( ( i >= 0 && i < (2 * n - 1) ) && (j >= 0 && j < n) ){
		if(dp[i][j] != -1)
			return dp[i][j];

		int ret_1 = 0, ret_2 = 0;

		if(j == 0 && i >= n - 1)
			ret_1 = grid[i][j] + rockClimbing(i + 1, j);

		else if(i >= n - 1 && grid[i + 1][j] == 0)
			ret_1 = grid[i][j] + rockClimbing(i + 1, j - 1);

		else if(i < n - 1){
			ret_1 = grid[i][j] + rockClimbing(i + 1, j);
			ret_2 = grid[i][j] + rockClimbing(i + 1, j + 1);
		}

		else if(i >= n - 1){
			ret_1 = grid[i][j] + rockClimbing(i + 1, j);
			ret_2 = grid[i][j] + rockClimbing(i + 1, j - 1);
		}

		return dp[i][j] = max(ret_1, ret_2);
	}
	else
		return 0;
}

int main(){
	//READ(".txt");

	int tc, case_no = 0;
	scanf("%d", &tc);

	while(tc--){
		mem(dp, -1);
		mem(grid, 0);

		scanf("%d", &n);

		rep(i, n){
			rep(j, i + 1){
				scanf("%d", &grid[i][j]);
			}
		}

		rep(i, n - 1){
			rep(j, n - i - 1){
				scanf("%d", &grid[i + n][j]);
			}
		}

		int ans = rockClimbing(0, 0);
		printf("Case %d: %d\n", ++case_no, ans);

	}

	return 0;
}
