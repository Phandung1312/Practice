#include<bits/stdc++.h>
// #include "debug.h"  

using namespace std;
#define int long long

bool check(vector<int>& books, int value){
    return false;
}
void process(vector<int>& books, int n, int t){
    vector<int> prevBooks(n + 1);
    prevBooks[0] = 0;
    for(int i = 1; i <= n ; i++){
        prevBooks[i] = prevBooks[i - 1] + books[i -1];
    }
    int k = 0;
    int l = 0;
    while(l + k  < n){
        if(prevBooks[l + k + 1 ] - prevBooks[l]  <= t ){
            k++;
        } else {
            l++;
        }
    }
    cout << k;

}
int32_t main(){
    int n, t;
    cin >> n >> t;
    vector<int> books(n);
    for(int i = 0; i < n; i++){
        cin >> books[i];
    }
    process(books, n, t);
    return 0;
}