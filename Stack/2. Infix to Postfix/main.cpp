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

// �켱������ ��ȯ�ϴ� �Լ�
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
		// �����ڰ� �߰ߵ� ��� 
		if(exp.at(i) == '+' || exp.at(i) == '-' || exp.at(i) == '*' || exp.at(i) == '/' || exp.at(i) == '%'){
			// 1. ������ ��� �ִ� ���(���� ����)
			if(mystack.empty()) mystack.push(exp.at(i));
			// 2. ������ top�� ���� ��ȣ�� ���(���� ����)
			else if(mystack.top() == '(') mystack.push(exp.at(i));
			// 3. ������ top���� �켱������ ���� ���(���� ����)
			else if(precedence(exp.at(i)) > precedence(mystack.top())) mystack.push(exp.at(i));
			// 4. ������ top���� �켱������ ���ų� ���� ���(����)
			else{
				while(!mystack.empty() && precedence(exp.at(i)) <= precedence(mystack.top())){
					cout << mystack.top();
					mystack.pop();
				}	
				mystack.push(exp.at(i));
			}	
		}
		// ���� ��ȣ�� �߰ߵ� ���(���� ����)
		else if(exp.at(i) == '('){
			mystack.push(exp.at(i));
		} 
		// �ݴ� ��ȣ�� �߰ߵ� ���(����)
		else if(exp.at(i) == ')'){
			// ���� ��ȣ�� �߰ߵ� ������ ��� 
			while(mystack.top() != '('){
				cout << mystack.top();
				mystack.pop();
			}
			// ���� ��ȣ�� ����
			mystack.pop(); 
		}
		// �ǿ����ڰ� �߰ߵ� ��� �״�� ��� 
		else {
			cout << exp.at(i);
		}
		
	}
	
	// ������ ��� ���� �ʴٸ� ���ÿ� �ִ� ���Ҹ� ��� ���
	while(!mystack.empty()){
		cout << mystack.top();
		mystack.pop();
	}

	return 0;

}
