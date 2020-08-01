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
		
		// ȭ��ǥ�� ����Ʈ�� �� ���� ����Ű�� ���� 
		while(count--){
			wheel.push_front(wheel.back());
			wheel.pop_back();	
		}
		
		// ȭ��ǥ�� ����Ű�� ��ġ�� ���ĺ��� ����
		// 1. �̹� ĭ�� ���ĺ��� ����Ǿ� �ִµ� �װͰ� �ٸ� ���ĺ��� �������� �ϴ� ���
		if(wheel.front() != '?' && wheel.front() != alpha){
			cout << "!";
			return 0;
		}
		// 2. �̹� �ٸ� ��ġ�� �ִ� ���ĺ��� �� ���� ��� 
		else if(checkDouble[(int)alpha] && wheel.front() != alpha){ 
			cout << "!";
			return 0;
		}
		// ���� ���� ��� 
		else{
			checkDouble[(int)alpha] = true;
			wheel.pop_front();       // ���� ȭ��ǥ ��ġ�� �ִ� ���Ҹ� ������ 
			wheel.push_front(alpha); // �Է����� ���� ���ĺ��� ���� 
		}
	}
	
	for(list<char>::iterator it = wheel.begin(); it != wheel.end(); it++){
		cout << *it;
	}
	
	return 0;
}
