#include <bits/stdc++.h>
using namespace std;

template <class T>
T addition(T x, T y) {
	T res = x + y;
	return res;
}

template <class T>
class Calculator {
private:
	T num1, num2;
public:
	Calculator(T num1, T num2) {
		this->num1 = num1;
		this->num2 = num2;
	}
	T add() { 
		return num1 + num2;
	}
	T subtract() { 
		return num1 - num2;
	}
	T multiply() { 
		return num1 * num2;
	}
	T divide() { 
		return num1 / num2;
	}
	void display_result() {
		cout << "Numbers are: " << num1 << " and " << num2 << '\n';
		cout << "Addition is: " << add() << '\n';
		cout << "Subtraction is: " << subtract() << '\n';
		cout << "Product is: " << multiply() << '\n';
		cout << "Division is: " << divide() << '\n';
	}
};

int main() {
	cout << addition<int>(5, 3) << '\n';
	cout << addition<float>(5.2, 3.3) << '\n';
	cout << addition<string>("abc", "def") << '\n';
	Calculator<int> x(5, 3);
	x.display_result();
}

//    8
//    8.5
//    abcdef
//    Numbers are: 5 and 3
//    Addition is: 8
//    Subtraction is: 2
//    Product is: 15
//    Division is: 1
