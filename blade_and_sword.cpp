#include<bits/stdc++.h>
#include "debug.h"  

using namespace std;
void process(vector<string> &grid, int m, int n){
    int result = 0;
    queue<pair<pair<int, int>, int>> q;
    
}
int main(){
    int T;
    cin >> T;
    cin.ignore();
    while(T--){
        int m, n;
        cin >> m >> n;
        vector<string> grid(m);
        for(int i = 0; i < m; i++){
            getline(cin, grid[i]);
        }
        process(grid, m, n);
    }
    return 0;
}