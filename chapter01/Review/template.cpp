#include <iostream>
#include <string>
using namespace std;

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << max(10, 20) << endl;                    // 출력: 20
    cout << max(3.14, 2.72) << endl;                // 출력: 3.14
    cout << max(string("hello"), string("world")) << endl;  // 출력: world

    return 0;
}
