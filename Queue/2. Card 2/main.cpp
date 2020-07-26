#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, temp;
	queue<int> myqueue;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		myqueue.push(i + 1);
	}
	
	while(myqueue.size() > 1){
		myqueue.pop(); // �� ���� �ִ� ī�带 �ٴڿ� ���� 
		temp = myqueue.front(); 
		myqueue.pop(); myqueue.push(temp); // ���� ���� �ִ� ī�带 �� �Ʒ��� �ű� 
	}
	
	cout << myqueue.front();
	
	return 0;
}
