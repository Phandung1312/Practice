#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int64_t>> a;
vector<vector<int>> adj;
vector<int> matchR;
vector<char> seen;

bool dfs(int v){
    for(int i: adj[v]){
        if(seen[i]) continue;
        seen[i] = 1;
        if(matchR[i] < 0 || dfs(matchR[i])){
            matchR[i] = v;
            return true;
        }
    }
    return false;
}

int solve(){
    cin >> n;
    a.assign(n, vector<int64_t>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<vector<int64_t>> S(n, vector<int64_t>(n+1, 0));
    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= 0; j--)
            S[i][j] = S[i][j+1] + a[i][j];
    }

    adj.assign(n, vector<int>());

    for(int v = 0; v < n; v++){
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= n; j++){
                if(S[i][j] == v){
                    adj[v].push_back(i);
                    break;
                }
            }
        }
    }

    matchR.assign(n, -1);

    int v;
    for(v = 0; v < n; v++){
        seen.assign(n, 0);
        if(!dfs(v)) break;
    }

    return v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        cout << solve() << "\n";
    }
    return 0;
}