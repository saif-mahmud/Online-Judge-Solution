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

	int n;
	while(1){
		scanf("%d", &n);
		if(n == 0)
			break;

        int x = n, limit = (int)sqrt(n);
        vi divisors;

        for(int i = 1; i <= limit; i++){
			if(x % i == 0){
				divisors.push_back(i);
				int d = x / i;

				if(d != i)
					divisors.push_back(d);
			}
        }

		int cnt = 0;

		for(int i = 0; i < divisors.size(); i++){
			for(int j = i; j < divisors.size(); j++){
				if(lcm(divisors[i], divisors[j]) == n){
					cnt++;
				}
			}
		}

		printf("%d %d\n", n, cnt);
	}
	return 0;
}
