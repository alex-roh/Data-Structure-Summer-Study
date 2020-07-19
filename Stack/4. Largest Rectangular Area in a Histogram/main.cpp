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
	
	// ���ÿ� ���� ���� �� ������׷��� �ε��� : width ����� ���ϰ� �ϱ� ���� 
	for(int i = 0; i < n; i++){
		// ���� ����ģ ������׷��� ������ top���� ũ�ų� ���� ���: ������ ����
		if(mystack.empty() || histogram[i] >= histogram[mystack.top()]){
			mystack.push(i);
		}
		// ���� ����ģ ������׷��� ������ top���� ���� ���: ����
		else{
			// ���ÿ��� ����ģ ������׷��� ���̿� ���ų� �� ���� ������׷��� �������� ���� ������ pop 
			while(!mystack.empty() && histogram[mystack.top()] >= histogram[i]){
				height = histogram[mystack.top()];
				mystack.pop();
				// ���� mystack.top()�� �ڱ� �Ʒ��� �ִ� ������׷��� ��ġ�� ����Ŵ 
				width = mystack.empty() ? i : i - mystack.top() - 1;
				rec = height * width;
				cout << "rec = " << height << " * " << width << " = " << rec << endl; 
				if(max < rec) max = rec;
			}	
			mystack.push(i);
		} 
	}
	
	// ���ÿ� ���� �ִ� ������׷��� ���̿� ���� ���簢���� ���� 
	// �������� ���� �ִٴ� ���� �ڽź��� �����ʿ� �ִ� ������׷��� ��� ���̰� �ڽź��� �� ũ�ٴ� ��
	// ���� (�ڽ��� ����) * (�ڱ� �Ʒ��� �ִ� ������׷��� ��ġ���� ������ �� �������� �Ÿ�)
	while(!mystack.empty()){
		height = histogram[mystack.top()];
		mystack.pop();
		// ���� mystack.top()�� �ڱ� �Ʒ��� �ִ� ������׷��� ��ġ�� ����Ŵ 
		width = mystack.empty() ? histogram.size() : histogram.size() - mystack.top() - 1;
		rec = height * width;
		cout << "rec = " << height << " * " << width << " = " << rec << endl; 
		if(max < rec) max = rec;
	}
	
	cout << max << endl;
	
	return 0;
}


