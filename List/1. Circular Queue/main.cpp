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
		// 큐의 front에 뽑고자 하는 원소가 있을 경우 
		if(mylist.front() == curr){
			mylist.pop_front();
		}
		// 큐의 front에 뽑고자 하는 원소가 없을 경우  
		else{
			// 2번 혹은 3번 연산이 이로운지 판별함 
			pos2 = 0; pos3 = 0;			
			// 2번은 리스트의 front부터 계산
			it = mylist.begin();
			while((*it) != curr){
				it++;
				pos2++;				
			}
			// 3번은 리스트의 back부터 계산 
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
			// 더 이로운 쪽으로 수행 
			if(pos3 >= pos2){
				// 2번 연산
				while(mylist.front() != curr){
					temp = mylist.front();
					mylist.pop_front();
					mylist.push_back(temp);
				}
				mylist.pop_front();
				result += pos2;
				// cout << "2, " << pos2 << "\n";
			} else{
				// 3번 연산
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
