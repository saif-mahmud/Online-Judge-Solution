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
typedef vector<int> vi;
typedef vector< pii > vii;
typedef map<int, int> mii;

#define INF (1 << 29)
#define PI (2.0 * acos(0.0))
#define MAXX 1000

int main(){
	//READ(".txt");

	int tc, case_no = 0;
	scanf("%d", &tc);

	while(tc--){
		int gcd, lcm;
		scanf("%d %d", &gcd, &lcm);

		if(lcm % gcd == 0)
			printf("%d %d\n", min(gcd, lcm), max(gcd, lcm));
		else
			printf("-1\n");
	}

	return 0;
}
