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
#define MAXX 1000

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){
	return a * (b / gcd(a, b));
}

int main(){
	//READ("UVa 412.txt");

	int n;
	while(1){
		scanf("%d", &n);
		if(n == 0)
			break;

		int a[n];
		rep(i, n)
			scanf("%d", &a[i]);

		int cnt = 0, couple = 0;

		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				couple++;
				if(gcd(a[i], a[j]) == 1)
					cnt++;
			}
		}

		if(cnt == 0)
			printf("No estimate for this data set.\n");
		else{
			double frac = (6.0 * (double)couple) / (double)cnt;
			double PI = sqrt(frac);
			printf("%0.6lf\n", PI);
		}
	}

	return 0;
}
