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
	
	// ���ʺ��� ��ȸ
	for(int i = 1; i < 1001; i++){
		if(beams[i] == 0) continue;
	
		// ������ top���� ���̰� ���ų� ���� ����� �߰��ϸ� skip
		// ������ top���� ���̰� ���� ����� �߰��� ������ ĳ��
		if(leftstack.empty() || beams[i] > beams[leftstack.top()]){
			// ������ ��� ���� �ʾҴٸ� ĳ���ϱ� ������ ���̸� ��� 
			if(!leftstack.empty()){
				height = beams[leftstack.top()];
				width = i - leftstack.top();
				leftstack.pop();
				area += height * width;
			}
			leftstack.push(i);
		}		
	} 
	
	// ���ʺ��� ��ȸ 
	for(int i = 1000; i > 0; i--){
		if(beams[i] == 0) continue;
	
		// ������ top���� ���̰� ���ų� ���� ����� �߰��ϸ� skip
		// ������ top���� ���̰� ���� ����� �߰��� ������ ĳ��
		if(rightstack.empty() || beams[i] > beams[rightstack.top()]){
			// ������ ��� ���� �ʾҴٸ� ĳ���ϱ� ������ ���̸� ��� 
			if(!rightstack.empty()){
				height = beams[rightstack.top()];
				width = rightstack.top() - i;
				rightstack.pop();
				area += height * width;
			}
			rightstack.push(i);
		}	
	} 
	
	// ���� ���� ����� ���̸� ��� 
	width = rightstack.top() - leftstack.top() + 1;
	height = beams[max_pos];
	area += width * height;
	cout << area << endl;
	
	return 0;
}
