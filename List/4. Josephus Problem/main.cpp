#include <iostream>
#include <list>

using namespace std;

int main(int argc, char** argv) {
	
	int n, k;
	list<int> people;
	list<int> result;
	list<int>::iterator it;
	cin >> n >> k;
	
	// 사람들에게 1번부터 n번까지 번호를 붙임 
	for(int i = 0; i < n; i++) people.push_back(i + 1);
	
	it = people.begin();
	while(!people.empty()){
		int temp = k;
		temp--;
		while(temp--){
			if(it == people.end()) it = people.begin();
			it++;
		}
		if(it == people.end()) it = people.begin();
		result.push_back(*it);
		it = people.erase(it);
	}
	
	it = result.begin();
	cout << "<" << *it;
	it++;
	for(; it != result.end(); it++){
		cout << ", " << *it;
	}
	cout << ">";
	
	return 0;
}
