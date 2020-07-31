#include <iostream>
#include <list>
 
using namespace std;
 
int main(int argc, char** argv) {
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, m, curr, temp;
	int result = 0;
	int pos2 = 0, pos3 = 0;
	list<int>::iterator it;
 
	cin >> n;
	list<int> mylist;
	for(int i = 1; i <= n; i++){
		mylist.push_back(i);
	}
 
	cin >> m;
 
	while(m > 0){
		cin >> curr;
		// cout << "curr = " << curr << "\n";
		// ť�� front�� �̰��� �ϴ� ���Ұ� ���� ��� 
		if(mylist.front() == curr){
			mylist.pop_front();
		}
		// ť�� front�� �̰��� �ϴ� ���Ұ� ���� ���  
		else{
			// 2�� Ȥ�� 3�� ������ �̷ο��� �Ǻ��� 
			pos2 = 0; pos3 = 0;			
			// 2���� ����Ʈ�� front���� ���
			it = mylist.begin();
			while((*it) != curr){
				it++;
				pos2++;				
			}
			// 3���� ����Ʈ�� back���� ��� 
			it = mylist.end();
			it--;
			// cout << "end: "<< *it << "\n";
			if((*it) == curr){
				pos3++;
			} else {
				while((*it) != curr){
					it--;
					pos3++;				
				}	
				if(mylist.front() != *it){
					pos3++;
				}
			}
			// �� �̷ο� ������ ���� 
			if(pos3 >= pos2){
				// 2�� ����
				while(mylist.front() != curr){
					temp = mylist.front();
					mylist.pop_front();
					mylist.push_back(temp);
				}
				mylist.pop_front();
				result += pos2;
				// cout << "2, " << pos2 << "\n";
			} else{
				// 3�� ����
				while(mylist.front() != curr){
					temp = mylist.back();
					mylist.pop_back();
					mylist.push_front(temp);
				}
				mylist.pop_front();
				result += pos3;
				// cout << "3, " << pos3 << "\n";
			}
		}
 
		/*
		for(list<int>::iterator it = mylist.begin(); it != mylist.end(); it++){
			cout << *it << " ";
		}
		cout << "\n\n";
		*/
 
		m--;
	}
 
	cout << result << "\n";
 
	return 0;
}
