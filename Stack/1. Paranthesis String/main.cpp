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

int main(int argc, char** argv) {

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		
		std::stack<char> mystack;
		int n, flag = 0;
		cin >> n;
		cin.ignore();

		while(n--){
				flag = 0;
				string str;
				getline(cin, str);
				for(int i = 0; i < str.size(); i++){
						// 여는 소괄호일 시 push
						if(str.at(i) == '('){
								mystack.push(str.at(i));
						}
						// 닫는 소괄호일 시 pop
						else{
								// 스택이 비어 있는 경우 잘못된 것
								if(mystack.empty()) {
										flag = -1;
										break;
								}
								else{
										mystack.pop();
								}
						}
				}
				if(flag == -1) cout << "NO" << endl;
				else if(mystack.empty()) cout << "YES" << endl;
				else if (!mystack.empty()) cout << "NO" << endl;
				clear(mystack);
		}
}
