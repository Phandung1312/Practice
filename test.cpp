#include <iostream>

using namespace std;

// Hàm đơn giản để tính tổng hai số
int tinhTong(int a, int b) {
    return a + b;
}

int main() {
    cout << "Hello, World!" << endl;
    
    int x = 5, y = 10;
    cout << "Tổng của " << x << " và " << y << " là: " << tinhTong(x, y) << endl;
    
    return 0;
}