#include <iostream>
#include <cstring>   // strcmp, strcpy, strlen 등
using namespace std;

int main()
{
    char s1[100], s2[100];

    cout << "첫 번째 문자열: ";
    cin >> s1;
    cout << "두 번째 문자열: ";
    cin >> s2;

    if (strcmp(s1, s2) == 0)
        cout << "2개의 문자열은 같습니다." << endl;
    else
        cout << "2개의 문자열은 다릅니다." << endl;

    return 0;
}

