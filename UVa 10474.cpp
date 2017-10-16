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

int binarySearch(int arr[], int low, int high, int x){
	if(high >= low){
		int mid = (low + high) / 2;

		if(arr[mid] == x){
			if(arr[mid - 1] == x && (mid - 1) >= 0)
				return binarySearch(arr, low, mid - 1, x);
			return mid;
		}

		if(arr[mid] > x)
			return binarySearch(arr, low, mid - 1, x);

		return binarySearch(arr, mid + 1, high, x);
	}
	return -1;
}

int main(){
	//READ("UVa 10474.txt");
	int case_no = 0;

	while(1){
		int n, q;

		scanf("%d %d", &n, &q);
		if(n == 0 && q == 0)
			break;

		int a[n];

		rep(i, n){
			scanf("%d", &a[i]);
		}

		sort(a, a + n);

		printf("CASE# %d:\n", ++case_no);

		rep(i, q){
			int x;
			scanf("%d", &x);

			int res = binarySearch(a, 0, n - 1, x);

			if(res == -1)
				printf("%d not found\n", x);
			else
				printf("%d found at %d\n", x, res + 1);
		}
	}
	return 0;
}
