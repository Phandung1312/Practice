#include <bits/stdc++.h>
#include "debug.h"  // Include file debug header

using namespace std;

int main() {
    DBG_SECTION("VÍ DỤ SỬ DỤNG HÀM DEBUG");
    
    // Debug các biến cơ bản
    int a = 10;
    double b = 3.14;
    char c = 'A';
    
    DBG(a);
    DBG(b);
    DBG(c);
    
    DBG_SEP();
    
    // Debug string
    string s = "Hello World";
    DBGS(s);
    
    DBG_SEP();
    
    // Debug vector
    vector<int> v = {1, 2, 3, 4, 5};
    DBGV(v);
    
    vector<string> vs = {"hello", "world", "debug"};
    DBGV(vs);
    
    DBG_SEP();
    
    // Debug mảng
    int arr[] = {10, 20, 30};
    DBGA(arr, 3);
    
    DBG_SEP();
    
    // Debug pair
    pair<int, string> p = {1, "first"};
    DBGP(p);
    
    DBG_SEP();
    
    // Debug set
    set<int> st = {3, 1, 4, 1, 5};
    DBGSET(st);
    
    DBG_SEP();
    
    // Debug map
    map<string, int> mp;
    mp["apple"] = 5;
    mp["banana"] = 3;
    DBGMAP(mp);
    
    DBG_SEP();
    
    // Debug có điều kiện
    int x = 15;
    DBG_IF(x > 10, x);
    DBG_IF(x < 5, x);  // Sẽ không in
    
    DBG_SEP();
    
    // Debug phạm vi
    DBG_RANGE("Số từ 1 đến 5", 1, 5);
    
    PRINT_LINE();
    
    return 0;
}
