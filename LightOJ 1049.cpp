#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

bool clk[105], anticlk[105];
int ans_clk, ans_antiCLK;

void init(){
	mem(clk, false);
	mem(anticlk, false);
	ans_clk = 0;
	ans_antiCLK = 0;
}

int main(){
	int t, u, v, w, case_no = 0, n;
	cin>>t;
	while(t--){
		init();
		cin>>n;
		for(int i = 0 ; i < n; i++){
			cin>>u>>v>>w;

			if(!clk[u] && !anticlk[v]){
				clk[u] = anticlk[v] = true;
				ans_clk += w;
			}

			else{
				anticlk[u] = clk[v] = true;
				ans_antiCLK += w;
			}
		}
		printf("Case %d: %d\n", ++case_no, min(ans_clk, ans_antiCLK));
	}
	return 0;
}
