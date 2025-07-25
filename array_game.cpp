#include<bits/stdc++.h>
// #include "debug.h"  

using namespace std;

#define int long long


int insertToArr(vector<int>& arr, int x){
    auto it = upper_bound(arr.begin(), arr.end(), x, greater<int>());
    int index = distance(arr.begin(), it);
    arr.insert(it ,x);
    // DBGV(arr);
    return index;
}
void process(vector<int>& arr, int n, int k){
    if(k >= 3)
    {
        cout << 0 << endl;
        return ;
    }
    sort(arr.begin(), arr.end(), greater<int>());
    // DBGV(arr);   
    vector<int> subarr(n - 1);
    for(int i = 0; i < n - 1; i++){
        subarr[i] = abs(arr[i] - arr[i + 1]);
    }
     sort(subarr.begin(), subarr.end(), greater<int>());
      int prevValue = subarr[0];
    // DBGV(subarr);   
    while(k--){
        // cout << "---------------------"<< endl;
        int minimum = subarr.back();
        // DBG(minimum);
        subarr.pop_back();
        //  // DBGV(subarr);
        int index = insertToArr(arr, minimum);
        // DBGV(arr);
        int leftValue = abs(arr[index - 1] - arr[index]);
        if(k >= 2 && !subarr.empty() ){
            int minimumArr = abs(minimum - subarr.back());
            if(minimumArr > leftValue){
                insertToArr(subarr, leftValue);
            }
        }
        else{
            insertToArr(subarr, leftValue);
        }
        // DBGV(subarr);
        if(index != arr.size() - 1){
            int rightValue = abs(arr[index] - arr[index + 1] );
             if(k >= 2 && !subarr.empty()){
            int minimumArr = abs(minimum - subarr.back());
            if(minimumArr > rightValue){
                insertToArr(subarr, rightValue);
            }
        }
        else{
            insertToArr(subarr, rightValue);
        }
            // DBGV(subarr);
        }
        if(arr.back() == 0){
            cout << arr.back() << endl;
            return;
        }
    }
    // DBGV(arr);
    cout << arr.back() << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        process(arr, n, k);
    }
    return 0;
}