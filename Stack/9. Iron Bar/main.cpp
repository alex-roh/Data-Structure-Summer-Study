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
        // 새로운 쇠막대기 혹은 레이저가 시작함
        if(arrangement.at(i) == '('){
        	mystack.push(arrangement.at(i));
		}
		// 쇠막대기 혹은 레이저가 끝남
		else{
			mystack.pop();
			// 레이저일 경우
			if(arrangement[i - 1] == '('){
				answer += mystack.size();
			}
			// 쇠막대기일 경우 
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
