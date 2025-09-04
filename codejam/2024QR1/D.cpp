#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array<ll,3> solve_one(const string &s){
    int m = (int)s.size();
    int n = m-1;
    array<int,3> idx; idx[0]=0; idx[1]=1; idx[2]=2;
    auto id = [&](char c)->int{
        if(c=='R') return 0;
        if(c=='G') return 1;
        return 2;
    };
    array<ll,3> cnt = {0,0,0};
    for(int i=0;i<n;i++){
        if(s[i]==s[i+1]) cnt[id(s[i])]++;
    }
    array<ll,3> best = cnt;
    const char letters[3] = {'R','G','B'};
    for(int p=0;p<m;p++){
        for(int t=0;t<3;t++){
            char nc = letters[t];
            if(nc==s[p]) continue;
            array<ll,3> d = {0,0,0};
            if(p-1>=0){
                if(s[p-1]==s[p]) d[id(s[p-1])]--;
                if(s[p-1]==nc) d[id(s[p-1])]++;
            }
            if(p < n){
                if(s[p]==s[p+1]) d[id(s[p])]--;
                if(nc==s[p+1]) d[id(s[p+1])]++;
            }
            for(int c=0;c<3;c++){
                ll val = cnt[c] + d[c];
                if(val > best[c]) best[c] = val;
            }
        }
    }
    return best;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int Nx,Ny,Nz;
        string Sx,Sy,Sz;
        cin>>Nx>>Ny>>Nz;
        cin>>Sx>>Sy>>Sz;
        array<ll,3> bx = solve_one(Sx);
        array<ll,3> by = solve_one(Sy);
        array<ll,3> bz = solve_one(Sz);
        vector<int> perm = {0,1,2};
        ll ans = 0;
        do{
            ll val = bx[perm[0]] * by[perm[1]] * bz[perm[2]];
            if(val>ans) ans=val;
        } while(next_permutation(perm.begin(), perm.end()));
        cout<<ans<<"\n";
    }
    return 0;
}