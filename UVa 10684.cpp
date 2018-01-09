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
	int n;

	while(1){
		scanf("%d", &n);

		if(n == 0)
			break;

		int a[n];

		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);

        int sum = 0, ans = 0;

        for(int i = 0; i < n; i++){
			sum += a[i];
			ans = max(ans, sum);

			if(sum < 0)
				sum = 0;
        }

        if(ans > 0)
			printf("The maximum winning streak is %d.\n", ans);
		else
			printf("Losing streak.\n");
	}

	return 0;
}

