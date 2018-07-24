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
#define MAXX 1000010

int failure[MAXX];
ll cnt;

void init(){
	cnt = 0;

	rep(i, MAXX)
		failure[i] = 0;
}

void KMP_Preprocess(string pattern, int m){
	failure[0] = 0;
	failure[1] = 0;

	for(int i = 2; i <= m; i++){
		int j = failure[i - 1];

		while(true){
			if(pattern[j] == pattern[i - 1]){
				failure[i] = j + 1;
				break;
			}
			if(j == 0){
				failure[i] = 0;
				break;
			}
			j = failure[j];
		}
	}
}

void KMP(string text, string pattern){
	int n = text.size();
	int m = pattern.size();

	KMP_Preprocess(pattern, m);

	int i = 0, j = 0;

	while(true){
		if(j == n)
			return;

		if(text[j] == pattern[i]){
			i++;
			j++;
			if(i == m)
				cnt++;
		}
		else{
			if(i == 0)
				j++;
			else
				i = failure[i];
		}
	}
	return;
}

int main(){
	//READ("LightOJ 1255.txt");
	//WRITE("Out.txt");

	int tc, case_no = 0;
	scanf("%d", &tc);

	string text, pattern;

	while(tc--){
		init();

		cin >> text;
		cin >> pattern;

		KMP(text, pattern);

		printf("Case %d: %lld\n", ++case_no, cnt);

	}

	return 0;
}
