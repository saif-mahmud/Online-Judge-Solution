#include <bits/stdc++.h>

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define iter(i,a,b) for(int i = (a) ; i < (b) ; i++)
#define mem(a,b) memset(a,b,sizeof(a))

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> iii;
typedef vector <pii> vii;

#define INF 1000000000
#define MAXX 1000

int main(){
	//READ("UVa 10611.txt");
	int n, q;
	scanf("%d", &n);

	int height[n];
	rep(i, n)
		scanf("%d", &height[i]);

	scanf("%d", &q);

	int x;

	while(q--){
		scanf("%d", &x);

		int above = upper_bound(height, height + n, x) - height;
		int below = above;
		below--;

		while(below >= 0 && height[below] == x)
			below--;

		if(below >= 0)
			printf("%d ", height[below]);
		else
			printf("X ");

		if(above == n)
			printf("X\n");
		else
			printf("%d\n", height[above]);
	}
	return 0;
}
