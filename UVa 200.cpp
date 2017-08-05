#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

vector<int> adj_l[26];
bool vis[26], valid[26];
stack<int> topo;
string str[10000];

void init()
{
    for(int i = 0; i < 26; i++)
    {
        adj_l[i].clear();
        str[i] = "";
    }
    mem(vis, false);
    mem(valid, false);
    while(!topo.empty())
        topo.pop();
}

void input(int u, int v)
{
    adj_l[u].push_back(v);
}

void dfs(int src)
{
    vis[src] = true;
    for(int i = 0; i < adj_l[src].size(); i++)
    {
        int v = adj_l[src][i];
        if(!vis[v])
            dfs(v);
    }
    topo.push(src);
    return;
}

void topo_sort()
{
    for(int i = 0; i < 26; i++)
    {
        if(!vis[i] && valid[i])
            dfs(i);
    }
    while (!topo.empty())
    {
        printf("%c", topo.top() + 'A');
        topo.pop();
    }
}

int main()
{
    READ("UVa 200.txt");
    int cnt = 1;
    while(cin>>str[0])
    {
        while (true)
        {
            cin>>str[cnt];
            if(str[cnt] == "#")
                break;
            cnt++;
        }
        for(int i = 0; i < (cnt - 1); i++)
        {
            for(int j = 0; ; j++)
            {
                if(str[i][j] == '\0' || str[i + 1][j] == '\0')
                    break;
                if(str[i][j] == str[i + 1][j])
                    continue;

                input(str[i][j] - 'A', str[i + 1][j] - 'A');

                valid[str[i][j] - 'A'] = true;
                valid[str[i + 1][j] - 'A'] = true;

                break;
            }
        }
        topo_sort();
        printf("\n");
        init();
        cnt = 1;
    }

    return 0;
}
