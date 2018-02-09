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

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return a * (b / gcd(a, b));
}

int main(){
	//READ(".txt");

	int tc, case_no = 0;
	//scanf("%d", &tc);

	int n;

	while(1){
		scanf("%d", &n);
		if(n == 0)
			break;

        int G = 0;
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                G += gcd(i,j);
            }
		}

		printf("%d\n", G);
	}

	return 0;
}
