#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {

   #include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {

    int answer = 0;
    string arrangement;
    stack<char> mystack;

    getline(cin, arrangement);
    
    for(int i = 0; i < arrangement.size(); i++){
        // ���ο� �踷��� Ȥ�� �������� ������
        if(arrangement.at(i) == '('){
        	mystack.push(arrangement.at(i));
		}
		// �踷��� Ȥ�� �������� ����
		else{
			mystack.pop();
			// �������� ���
			if(arrangement[i - 1] == '('){
				answer += mystack.size();
			}
			// �踷����� ��� 
			else{
				answer++;
			}
		} 
        
    }

    cout << answer;
    
    return 0;
}
    
    return 0;
}
