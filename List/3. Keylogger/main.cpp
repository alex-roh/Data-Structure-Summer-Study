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
		// �н������ ����� ����Ʈ�� �ݺ��� 
		list<char> password;
		list<char>::iterator it;
		// ����Ʈ�� ĳ�� 
		getline(cin, str);
		len = str.size();
		// ��й�ȣ�� ���ϴ� �˰���
		it = password.begin(); // �н����忡 ���� �ݺ���  
		
		for(int i = 0; i < len; i++){
			switch(str.at(i)){
				// �н����� Ŀ���� �������� �̵� 
				case '<':
					// �н����� �ݺ��ڸ� ������ 
					if(it != password.begin()){
						it--;
					}
					break;	
				// �н����� Ŀ���� ���������� �̵� 
				case '>':
					// �н����� �ݺ��ڸ� ������ 
					if(it != password.end()){
						it++;	
					}
					break;
				// �н����忡�� ���Ҹ� ���� 
				case '-':
					if(!password.empty() && it == password.begin()) break;
					if(!password.empty()){
						it = password.erase(--it);
					}
					// �н����� �ݺ��ڰ� ���� ����Ű�� ��ġ�� ���Ҹ� ���� 
					break;
				default:
					password.insert(it, str.at(i)); // �н����� ����Ʈ�� ���ڸ� �߰���
					break;			
			}
		}
		
		// �н����带 ���
		for(list<char>::iterator iter = password.begin(); iter != password.end(); iter++){
			cout << *iter;
		} 
		cout << "\n";
	}
	
	return 0;
}
