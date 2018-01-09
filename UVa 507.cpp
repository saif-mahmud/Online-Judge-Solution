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
	//READ("UVa 507.txt");

	int tc, case_no = 0;
	scanf("%d", &tc);

	while(tc--){
		int n;
		scanf("%d", &n);

		n--;

		int a[n];

		int startIdx = 1, curSum = 0, maxSum = 0, maxStartIdx, maxEndIdx;

		iter(i, 1, n + 1)
			scanf("%d", &a[i]);

		for(int endIdx = 1; endIdx <= n; endIdx++){
            curSum += a[endIdx];

            if(curSum < 0){
				startIdx = endIdx + 1;
				curSum = 0;
            }

            if(curSum > maxSum || (curSum == maxSum && ( (maxEndIdx - maxStartIdx) < (endIdx - startIdx) ) )){
                maxSum = curSum;
                maxStartIdx = startIdx;
                maxEndIdx = endIdx;
            }
		}

		if(maxSum > 0)
			printf("The nicest part of route %d is between stops %d and %d\n", ++case_no, maxStartIdx, maxEndIdx + 1);
		else
			printf("Route %d has no nice parts\n", ++case_no);
	}

	return 0;
}
