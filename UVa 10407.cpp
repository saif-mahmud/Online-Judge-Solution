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
	//READ("UVa 10407.txt");
	int n;
	scanf("%d", &n);
	while(n){
		vi input;

		while(n){
			input.push_back(n);
			scanf("%d", &n);
		}

		unique(input.begin(), input.end());

		vi d;
		for(int i = 1; i < input.size(); i++)
			d.push_back(input[i] - input[i - 1]);

		int x = abs(d[0]);

		for(int i = 1; i < d.size(); i++){
			x = gcd(x, abs(d[i]));
		}

		printf("%d\n", x);

		scanf("%d", &n);
	}
	return 0;
}
