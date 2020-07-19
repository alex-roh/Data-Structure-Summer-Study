#include <iostream>
#include <string>
#include <stack>
#define ASCII 65

using namespace std;
int value[26];

template<typename T>
void clear( std::stack<T> &q )
{
   stack<T> empty;
   swap(q, empty);
}

double calculate(double oprd1, double oprd2, char token){
	switch(token){
		case '+':
			return oprd1 + oprd2;
			break;
		case '-':
			return oprd1 - oprd2;
			break;
		case '*':
			return oprd1 * oprd2;
			break;
		case '/':
			return oprd1 / oprd2;
			break;
	}
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::stack<double> mystack;
	string exp;	
	int n, length;
	double oprd1, oprd2;
	double result;
	
	cin >> n;
	cin.ignore();
	getline(cin, exp);
	for(int i = 0; i < n; i++) cin >> value[i];	
	length = exp.size();
	
	for(int i = 0; i < length; i++){
		// 연산자가 발견된 경우
		if(exp.at(i) == '+' || exp.at(i) == '-' || 
			 exp.at(i) == '*' || exp.at(i) == '/')
		{	
			oprd2 = mystack.top(); mystack.pop();
			oprd1 = mystack.top(); mystack.pop();
			result = calculate(oprd1, oprd2, exp.at(i));
			mystack.push(result);
		}
		// 피연산자가 발견된 경우 
		else{
			oprd1 = value[(int)exp.at(i) - ASCII];
			mystack.push(oprd1);
		}
	}
	
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << mystack.top();
	
	return 0;	
}

