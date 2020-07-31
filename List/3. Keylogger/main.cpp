#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	static int debug = 0;
	string str;
	int n, len;
	
	cin >> n;
	cin.ignore();
	
	while(n--){
		// 패스워드로 사용할 리스트와 반복자 
		list<char> password;
		list<char>::iterator it;
		// 리스트에 캐싱 
		getline(cin, str);
		len = str.size();
		// 비밀번호를 구하는 알고리즘
		it = password.begin(); // 패스워드에 대한 반복자  
		
		for(int i = 0; i < len; i++){
			switch(str.at(i)){
				// 패스워드 커서를 왼쪽으로 이동 
				case '<':
					// 패스워드 반복자를 움직임 
					if(it != password.begin()){
						it--;
					}
					break;	
				// 패스워드 커서를 오른쪽으로 이동 
				case '>':
					// 패스워드 반복자를 움직임 
					if(it != password.end()){
						it++;	
					}
					break;
				// 패스워드에서 원소를 삭제 
				case '-':
					if(!password.empty() && it == password.begin()) break;
					if(!password.empty()){
						it = password.erase(--it);
					}
					// 패스워드 반복자가 현재 가리키는 위치의 원소를 삭제 
					break;
				default:
					password.insert(it, str.at(i)); // 패스워드 리스트에 문자를 추가함
					break;			
			}
		}
		
		// 패스워드를 출력
		for(list<char>::iterator iter = password.begin(); iter != password.end(); iter++){
			cout << *iter;
		} 
		cout << "\n";
	}
	
	return 0;
}
