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
#define MAXX 10005

ll dp[MAXX];

int main(){
	iter(i, 1, MAXX)
		dp[i] = 0;

	dp[0] = 1;

	iter(i, 1, 22){
		int cube = i * i * i;
		iter(j, cube, MAXX){
			dp[j] += dp[j - cube];
		}
	}

	int n;

	while(cin>>n){
		cout<<dp[n]<<endl;
	}

	return 0;
}
