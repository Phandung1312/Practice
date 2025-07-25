#include<bits/stdc++.h>
// #include "debug.h"  

using namespace std;
void process(vector<int>& w, int n){
    sort(w.begin(), w.end());
    int rLimit = w[n - 1] * 2;
    int lLimit = w[0] * 2;
    //DBG(rLimit);
    //DBG(lLimit);
    //DBGV(w);
    int result = -2;
    for(int i = rLimit; i >= lLimit; i--){
        int count = 0;
        int l = 0;
        int r = n - 1;
        while( l < r){
            int currentSume = w[l] + w[r];
            if(currentSume == i){
                count += 1;
                l++;
                r--;
            }
           else if(currentSume > i){
                r--;
            }
            else {
                l++;
            }
        }
        result = max(result, count);
    }

    cout << result << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> w(n);
        for(int i = 0; i < n; i++){
            cin >> w[i];
        }
        process(w, n);
    }
    return 0;
}