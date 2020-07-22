#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

template<typename T>
void clear( std::stack<T> &q )
{
   stack<T> empty;
   swap(q, empty);
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> arr;
	stack<int> mystack;
	
	int n, input, card = 1, min = INT_MIN;
	bool flag = true;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> input;
		arr.push_back(input);
	}
	
	// ���� ������ ���� �� �ִ��� �˻� 
	for(int i = 0; i < n; i++){
		// ū ���� �߰ߵǸ� ���ÿ� ������� 
		if(mystack.empty() || mystack.top() < arr[i]) {
			mystack.push(arr[i]);
			min = arr[i];	
		}
		// ���� ��(���� �� x)�� �߰ߵǸ� min�� ĳ�� 
		else{
			if(min > arr[i]) min = arr[i];
			// min���� Ŭ ��� ���� ������ ���� �� ����
			if(arr[i] > min) {
				flag = false;
				break;
			}
		} 
	}
	
	// ������ �ʱ�ȭ
	clear(mystack); 
	
	// ���� ������ ���� �� ������ NO�� ����ϰ�, ���� �� ������ ����� ����� �����
	if(flag == false){
		cout << "NO\n";
	} else{
		for(int i = 0; i < n; i++){
			// stack�� top�� ���� �迭�� ���Һ��� �� ũ�ٸ� pop 
			if(!mystack.empty() && mystack.top() >= arr[i]){
				// top�� ���� �迭�� ���Һ��� �۾����� break 
				while(!mystack.empty() && mystack.top() >= arr[i]) {
					mystack.pop();
					cout << "-\n";
				}
			}	
			// stack�� ��� �ְų� stack�� top���� ���� �迭�� ���Ұ� �� �۴ٸ� push 
			else{
				// card�� arr[i]�ʰ��� �� Ż�� 
				while(card <= arr[i]){
					mystack.push(card);
					cout << "+\n";
					card++;
				}
				// ���ÿ� ���������� ���� ���Ҹ� pop�Ѵ� 
				mystack.pop();
				cout << "-\n";
			}
		}
	}
	
	return 0;
}
