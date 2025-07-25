#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

// Hàm DEBUG chung cho toàn bộ dự án
template<typename T>
void PRINT_DEBUG(const string& name, const T& value) {
    cout << "[DEBUG] " << name << " = " << value << endl;
}

// DEBUG cho vector
template<typename T>
void PRINT_VECTOR(const string& name, const vector<T>& vec) {
    cout << "[DEBUG] " << name << " = [";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if(i < vec.size() - 1) cout << ", ";
    }
    cout << "] (size: " << vec.size() << ")" << endl;
}

// DEBUG cho vector 2D
template<typename T>
void PRINT_VECTOR_2D(const string& name, const vector<vector<T>>& vec2d) {
    cout << "[DEBUG] " << name << " = [" << endl;
    for(int i = 0; i < vec2d.size(); i++) {
        cout << "  [" << i << "]: [";
        for(int j = 0; j < vec2d[i].size(); j++) {
            cout << vec2d[i][j];
            if(j < vec2d[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if(i < vec2d.size() - 1) cout << ",";
        cout << endl;
    }
    cout << "] (size: " << vec2d.size() << " x " << (vec2d.empty() ? 0 : vec2d[0].size()) << ")" << endl;
}

// DEBUG cho mảng
template<typename T>
void PRINT_ARRAY(const string& name, const T arr[], int size) {
    cout << "[DEBUG] " << name << " = [";
    for(int i = 0; i < size; i++) {
        cout << arr[i];
        if(i < size - 1) cout << ", ";
    }
    cout << "] (size: " << size << ")" << endl;
}

// DEBUG cho string
void PRINT_STRING(const string& name, const string& str) {
    cout << "[DEBUG] " << name << " = \"" << str << "\" (length: " << str.length() << ")" << endl;
}

// DEBUG cho pair
template<typename T1, typename T2>
void PRINT_PAIR(const string& name, const pair<T1, T2>& p) {
    cout << "[DEBUG] " << name << " = (" << p.first << ", " << p.second << ")" << endl;
}

// DEBUG cho set
template<typename T>
void PRINT_SET(const string& name, const set<T>& s) {
    cout << "[DEBUG] " << name << " = {";
    bool first = true;
    for(const auto& elem : s) {
        if(!first) cout << ", ";
        cout << elem;
        first = false;
    }
    cout << "} (size: " << s.size() << ")" << endl;
}

// DEBUG cho map
template<typename K, typename V>
void PRINT_MAP(const string& name, const map<K, V>& m) {
    cout << "[DEBUG] " << name << " = {";
    bool first = true;
    for(const auto& elem : m) {
        if(!first) cout << ", ";
        cout << elem.first << ": " << elem.second;
        first = false;
    }
    cout << "} (size: " << m.size() << ")" << endl;
}

// DEBUG cho nhiều biến cùng lúc với số dòng
#define PRINT_LINE() cout << "[DEBUG] Dòng " << __LINE__ << " trong file " << __FILE__ << endl

// Macro để debug nhanh
#define DBG(x) PRINT_DEBUG(#x, x)
#define DBGV(x) PRINT_VECTOR(#x, x)
#define DBGV2D(x) PRINT_VECTOR_2D(#x, x)
#define DBGS(x) PRINT_STRING(#x, x)
#define DBGP(x) PRINT_PAIR(#x, x)
#define DBGSET(x) PRINT_SET(#x, x)
#define DBGMAP(x) PRINT_MAP(#x, x)
#define DBGA(x, n) PRINT_ARRAY(#x, x, n)

// Debug với điều kiện
#define DBG_IF(condition, x) if(condition) { DBG(x); }

// Debug phạm vi trong loop
#define DBG_RANGE(name, start, end) do { \
    cout << "[DEBUG] " << name << " từ " << start << " đến " << end << ": "; \
    for(int debug_i = start; debug_i <= end; debug_i++) { \
        cout << debug_i << " "; \
    } \
    cout << endl; \
} while(0)

// Separator để chia các phần debug
#define DBG_SEP() cout << "[DEBUG] ================================" << endl
#define DBG_SECTION(name) cout << "[DEBUG] === " << name << " ===" << endl

#endif
