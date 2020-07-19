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
						// ���� �Ұ�ȣ�� �� push
						if(str.at(i) == '('){
								mystack.push(str.at(i));
						}
						// �ݴ� �Ұ�ȣ�� �� pop
						else{
								// ������ ��� �ִ� ��� �߸��� ��
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
