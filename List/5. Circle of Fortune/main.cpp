#include <iostream>
#include <list>

using namespace std;

bool checkDouble[128] = { false };

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k, count;
	cin >> n >> k;
	list<char> wheel(n, '?');
	char alpha;
	
	while(k--){
		cin >> count;
		cin >> alpha;
		
		// 화살표는 리스트의 맨 앞을 가리키고 있음 
		while(count--){
			wheel.push_front(wheel.back());
			wheel.pop_back();	
		}
		
		// 화살표가 가리키는 위치에 알파벳을 삽입
		// 1. 이미 칸에 알파벳이 저장되어 있는데 그것과 다른 알파벳을 넣으려고 하는 경우
		if(wheel.front() != '?' && wheel.front() != alpha){
			cout << "!";
			return 0;
		}
		// 2. 이미 다른 위치에 있는 알파벳이 또 나온 경우 
		else if(checkDouble[(int)alpha] && wheel.front() != alpha){ 
			cout << "!";
			return 0;
		}
		// 문제 없는 경우 
		else{
			checkDouble[(int)alpha] = true;
			wheel.pop_front();       // 현재 화살표 위치에 있는 원소를 빼내고 
			wheel.push_front(alpha); // 입력으로 들어온 알파벳을 삽입 
		}
	}
	
	for(list<char>::iterator it = wheel.begin(); it != wheel.end(); it++){
		cout << *it;
	}
	
	return 0;
}
