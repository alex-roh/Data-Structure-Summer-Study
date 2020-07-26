#include <iostream>
#include <stack>
#include <map>

using namespace std;

int func(stack<int> &s, int line, int fretNum){
		
	int add = 0;
		
	// ������ ��� �ְų� top�� fretNum���� �۴ٸ� 
	if(s.empty() || s.top() < fretNum){
		add++;
		s.push(fretNum);
	}
	// ������ top���� ���� ���Ұ� �� �۴ٸ� pop 
	else{
		while(!s.empty() && s.top() > fretNum){
			add++;
			s.pop();
		}
		if(s.empty() || !s.empty() && s.top() != fretNum){
			s.push(fretNum);
			add++;
		}
	}
	
	return add;
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, fret;
	int line, fretNum;
	int result = 0;
	
	stack<int> first;
	stack<int> second;
	stack<int> third;
	stack<int> forth;
	stack<int> fifth;
	stack<int> sixth;
	
	cin >> n;
	cin >> fret;
	
	for(int i = 0; i < n; i++){
		cin >> line; cin >> fretNum;
		// ������ ����ų� ������ top���� ���� ���Ұ� �� ũ�ٸ� push
		switch(line){
			case 1:
				result += func(first, line, fretNum);
				break;
			case 2:
				result += func(second, line, fretNum);
				break;
			case 3:
				result += func(third, line, fretNum);
				break;
			case 4:
				result += func(forth, line, fretNum);
				break;
			case 5:
				result += func(fifth, line, fretNum);
				break;
			case 6:
				result += func(sixth, line, fretNum);
				break;
		}
	}
	
	cout << result;
	
	return 0;
}
