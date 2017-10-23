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
#define MAXX 1005

#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

int a[MAXX][3];

int main(){
	//READ(".txt");

	int tc, case_no = 0;
	scanf("%d", &tc);

	while(tc--){
		int n;
		scanf("%d", &n);

		rep(i, n)
			scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);

		iter(i, 1, n){
			a[i][0] += min(a[i - 1][1], a[i - 1][2]);
			a[i][1] += min(a[i - 1][0], a[i - 1][2]);
			a[i][2] += min(a[i - 1][0], a[i - 1][1]);
		}

		int ans = min3(a[n - 1][0], a[n - 1][1], a[n - 1][2]);

		printf("Case %d: %d\n", ++case_no, ans);

	}

	return 0;
}
