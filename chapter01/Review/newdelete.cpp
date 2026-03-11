#include <iostream>
using namespace std;

int main() {
    int n = 5;

    int* arr = new int[n];   // 동적 배열 생성

    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;   // 배열 메모리 해제

    return 0;
}
