#include <iostream>
#include <string>
#include <stack>

using namespace std;

template<typename T>
void clear( std::stack<T> &q )
{
   stack<T> empty;
   swap(q, empty);
}

// 우선순위를 반환하는 함수
int precedence(char oper){
	if(oper == '(')
		return 0;
	else if(oper == '+' || oper == '-'){
		return 1;
	}
	else if(oper == '*' || oper == '/' || oper == '%'){
		return 2;
	}
} 

int main(int argc, char** argv) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	std::stack<char> mystack;
	string exp;
	getline(cin, exp);
	int length = exp.size();
	
	// cout << "length is " << length << endl;
	
	for(int i = 0; i < length; i++){
		// cout << "current index is " << i << ", and char is " << exp.at(i) << endl;
		if(exp.at(i) == ' ') continue;
		// 연산자가 발견된 경우 
		if(exp.at(i) == '+' || exp.at(i) == '-' || exp.at(i) == '*' || exp.at(i) == '/' || exp.at(i) == '%'){
			// 1. 스택이 비어 있는 경우(결정 보류)
			if(mystack.empty()) mystack.push(exp.at(i));
			// 2. 스택의 top이 여는 괄호인 경우(결정 보류)
			else if(mystack.top() == '(') mystack.push(exp.at(i));
			// 3. 스택의 top보다 우선순위가 높은 경우(결정 보류)
			else if(precedence(exp.at(i)) > precedence(mystack.top())) mystack.push(exp.at(i));
			// 4. 스택의 top보다 우선순위가 낮거나 같은 경우(결정)
			else{
				while(!mystack.empty() && precedence(exp.at(i)) <= precedence(mystack.top())){
					cout << mystack.top();
					mystack.pop();
				}	
				mystack.push(exp.at(i));
			}	
		}
		// 여는 괄호가 발견된 경우(결정 보류)
		else if(exp.at(i) == '('){
			mystack.push(exp.at(i));
		} 
		// 닫는 괄호가 발견된 경우(결정)
		else if(exp.at(i) == ')'){
			// 여는 괄호가 발견될 때까지 출력 
			while(mystack.top() != '('){
				cout << mystack.top();
				mystack.pop();
			}
			// 여는 괄호를 삭제
			mystack.pop(); 
		}
		// 피연산자가 발견된 경우 그대로 출력 
		else {
			cout << exp.at(i);
		}
		
	}
	
	// 스택이 비어 있지 않다면 스택에 있는 원소를 모두 출력
	while(!mystack.empty()){
		cout << mystack.top();
		mystack.pop();
	}

	return 0;

}
