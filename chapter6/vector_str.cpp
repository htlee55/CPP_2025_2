#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	vector<string> vec;		// 벡터를 생성한다. 

	vec.push_back("MILK");		// 벡터의 끝에 자료를 저장한다.
	vec.push_back("BREAD");
	vec.push_back("BUTTER");
	for (auto e : vec) {
		cout << " " << e;
	}
	cout << endl;
	return 0;
}
