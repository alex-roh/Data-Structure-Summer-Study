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
			// ������ ��� �ְų� top�� ���� ���ҿ� ��ġ���� ���� ��� �������
			if(mystack.empty() || mystack.top() != str.at(i))
			{
				mystack.push(str.at(i));
			}
			// ������ top�� �ִ� ���ĺ��� ���� ���ĺ��� ��ġ�� -> pop 
			else{
				mystack.pop();
			}
		}
		// ������ ��� �ִٸ� ���� �ܾ��� ���� �ϳ� �߰��� 
		if(mystack.empty()) num++;
		else clear(mystack);
	}
	
	cout << num << "\n";
	
	return 0;
}
