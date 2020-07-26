#include <iostream>
#include <stack>
#include <string>

using namespace std;

template<typename T>
void clear( std::stack<T> &s )
{
   std::stack<T> empty;
   std::swap(s, empty);
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int num = 0;
	string str;
	stack<char> mystack;
	
	cin >> n;
	cin.ignore();
		
	for(int i = 0; i < n; i++){
		getline(cin, str);
		for(int i = 0; i < str.size(); i++){
			// 스택이 비어 있거나 top이 현재 원소와 일치하지 않을 경우 집어넣음
			if(mystack.empty() || mystack.top() != str.at(i))
			{
				mystack.push(str.at(i));
			}
			// 스택의 top에 있는 알파벳이 현재 알파벳과 일치함 -> pop 
			else{
				mystack.pop();
			}
		}
		// 스택이 비어 있다면 좋은 단어의 수를 하나 추가함 
		if(mystack.empty()) num++;
		else clear(mystack);
	}
	
	cout << num << "\n";
	
	return 0;
}
