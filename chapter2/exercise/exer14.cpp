# include <iostream>
using namespace std;

int main()
{	char op;
	double num1, num2;
	cout << "연산의 종류: ";
	cin >> op;
	cout << "숫자를 입력하시오: ";
	cin >> num1 >> num2;
	switch (op)
	{
	case '+':
		cout << "계산의 결과 : " <<num1 + num2;
		break;
	case '-':
		cout << "계산의 결과 : "  << num1 - num2;
		break;
	case '*':
		cout << "계산의 결과 : " << num1*num2;
		break;
	case '/':
		if( num2!=0)
			cout << "계산의 결과 : "  << num1 / num2;
		break;
	default:
		cout << "지원되지 않는 연산자" << endl;
		break;
	}
	cout << endl;
	return 0;
}
