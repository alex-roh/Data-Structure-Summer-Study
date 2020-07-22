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
	
	// 스택 수열을 만들 수 있는지 검사 
	for(int i = 0; i < n; i++){
		// 큰 수가 발견되면 스택에 집어넣음 
		if(mystack.empty() || mystack.top() < arr[i]) {
			mystack.push(arr[i]);
			min = arr[i];	
		}
		// 작은 수(같은 수 x)가 발견되면 min에 캐싱 
		else{
			if(min > arr[i]) min = arr[i];
			// min보다 클 경우 스택 수열을 만들 수 없음
			if(arr[i] > min) {
				flag = false;
				break;
			}
		} 
	}
	
	// 스택을 초기화
	clear(mystack); 
	
	// 스택 수열을 만들 수 없으면 NO를 출력하고, 만들 수 있으면 만드는 방법을 출력함
	if(flag == false){
		cout << "NO\n";
	} else{
		for(int i = 0; i < n; i++){
			// stack의 top이 현재 배열의 원소보다 더 크다면 pop 
			if(!mystack.empty() && mystack.top() >= arr[i]){
				// top이 현재 배열의 원소보다 작아지면 break 
				while(!mystack.empty() && mystack.top() >= arr[i]) {
					mystack.pop();
					cout << "-\n";
				}
			}	
			// stack이 비어 있거나 stack의 top보다 현재 배열의 원소가 더 작다면 push 
			else{
				// card가 arr[i]초과일 시 탈출 
				while(card <= arr[i]){
					mystack.push(card);
					cout << "+\n";
					card++;
				}
				// 스택에 마지막으로 넣은 원소를 pop한다 
				mystack.pop();
				cout << "-\n";
			}
		}
	}
	
	return 0;
}
