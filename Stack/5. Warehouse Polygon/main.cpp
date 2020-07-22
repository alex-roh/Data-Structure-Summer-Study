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
	stack<int> leftstack;
	stack<int> rightstack;
	int beams[1001] = { 0 };
	
	int n, pos_t, height_t;
	int start, end; 
	int height, width, area = 0;
	int max = INT_MIN, max_pos;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> pos_t;
		cin >> height_t;
		beams[pos_t] = height_t;
		if(height_t > max) {
			max_pos = pos_t;
			max = height_t;
		}
	}
	
	// 앞쪽부터 순회
	for(int i = 1; i < 1001; i++){
		if(beams[i] == 0) continue;
	
		// 스택의 top보다 높이가 같거나 낮은 기둥을 발견하면 skip
		// 스택의 top보다 높이가 높은 기둥을 발견할 때에만 캐싱
		if(leftstack.empty() || beams[i] > beams[leftstack.top()]){
			// 스택이 비어 있지 않았다면 캐싱하기 직전에 넓이를 계산 
			if(!leftstack.empty()){
				height = beams[leftstack.top()];
				width = i - leftstack.top();
				leftstack.pop();
				area += height * width;
			}
			leftstack.push(i);
		}		
	} 
	
	// 뒤쪽부터 순회 
	for(int i = 1000; i > 0; i--){
		if(beams[i] == 0) continue;
	
		// 스택의 top보다 높이가 같거나 낮은 기둥을 발견하면 skip
		// 스택의 top보다 높이가 높은 기둥을 발견할 때에만 캐싱
		if(rightstack.empty() || beams[i] > beams[rightstack.top()]){
			// 스택이 비어 있지 않았다면 캐싱하기 직전에 넓이를 계산 
			if(!rightstack.empty()){
				height = beams[rightstack.top()];
				width = rightstack.top() - i;
				rightstack.pop();
				area += height * width;
			}
			rightstack.push(i);
		}	
	} 
	
	// 가장 높은 기둥의 넓이를 계산 
	width = rightstack.top() - leftstack.top() + 1;
	height = beams[max_pos];
	area += width * height;
	cout << area << endl;
	
	return 0;
}
