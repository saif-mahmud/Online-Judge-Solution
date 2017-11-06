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

string str;
int dp[MAXX][MAXX];

int solve(int i, int j){
	if(i >= j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];

	if(str[i] == str[j])
		dp[i][j] = solve(i + 1, j - 1);
	else
		dp[i][j] = 1 + min(solve(i + 1, j), solve(i, j - 1));

	return dp[i][j];
}


int main(){
	//READ("LightOJ 1033.txt");

	int tc, case_no = 0;
	scanf("%d", &tc);

	while(tc--){
		cin>>str;
		mem(dp, -1);
		int res = solve(0, str.size() - 1);
		printf("Case %d: %d\n", ++case_no, res);
	}

	return 0;
}
