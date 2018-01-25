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

int n, a[101][101], subRect, maxSubRect;

int main(){
	//READ("UVa 108.txt");

	while(scanf("%d", &n) != EOF){
		rep(i, n){
			rep(j, n){
				scanf("%d", &a[i][j]);

				if(j > 0)
					a[i][j] += a[i][j - 1];
			}
		}

		maxSubRect = -127 * 100 * 100;

		rep(l, n){
			iter(r, l, n){
				subRect = 0;

				rep(row, n){
					if(l > 0)
						subRect += a[row][r] - a[row][l - 1];
					else
						subRect += a[row][r];

					if(subRect < 0)
						subRect = 0;

					maxSubRect = max(maxSubRect, subRect);
				}
			}
		}
		printf("%d\n", maxSubRect);
	}
	return 0;
}
