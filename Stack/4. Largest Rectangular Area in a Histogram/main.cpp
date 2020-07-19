#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

int main(int argc, char** argv) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> mystack;
	vector<int> histogram;
	int n, temp;
	int height, width, max = INT_MIN;
	int rec;
	
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> temp;
		histogram.push_back(temp);	
	}
	
	// 스택에 들어가는 것은 각 히스토그램의 인덱스 : width 계산을 편하게 하기 위함 
	for(int i = 0; i < n; i++){
		// 지금 마주친 히스토그램이 스택의 top보다 크거나 같은 경우: 결정을 보류
		if(mystack.empty() || histogram[i] >= histogram[mystack.top()]){
			mystack.push(i);
		}
		// 지금 마주친 히스토그램이 스택의 top보다 작은 경우: 결정
		else{
			// 스택에서 마주친 히스토그램의 높이와 같거나 더 높은 히스토그램이 남아있지 않을 때까지 pop 
			while(!mystack.empty() && histogram[mystack.top()] >= histogram[i]){
				height = histogram[mystack.top()];
				mystack.pop();
				// 이제 mystack.top()은 자기 아래에 있는 히스토그램의 위치를 가리킴 
				width = mystack.empty() ? i : i - mystack.top() - 1;
				rec = height * width;
				cout << "rec = " << height << " * " << width << " = " << rec << endl; 
				if(max < rec) max = rec;
			}	
			mystack.push(i);
		} 
	}
	
	// 스택에 남아 있는 히스토그램의 높이에 대한 직사각형을 구함 
	// 아직까지 남아 있다는 것은 자신보다 오른쪽에 있는 히스토그램의 모든 높이가 자신보다 더 크다는 뜻
	// 따라서 (자신의 높이) * (자기 아래에 있는 히스토그램의 위치부터 오른쪽 맨 끝까지의 거리)
	while(!mystack.empty()){
		height = histogram[mystack.top()];
		mystack.pop();
		// 이제 mystack.top()은 자기 아래에 있는 히스토그램의 위치를 가리킴 
		width = mystack.empty() ? histogram.size() : histogram.size() - mystack.top() - 1;
		rec = height * width;
		cout << "rec = " << height << " * " << width << " = " << rec << endl; 
		if(max < rec) max = rec;
	}
	
	cout << max << endl;
	
	return 0;
}


