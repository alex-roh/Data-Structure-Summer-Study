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
		myqueue.pop(); // 맨 위에 있는 카드를 바닥에 버림 
		temp = myqueue.front(); 
		myqueue.pop(); myqueue.push(temp); // 제일 위에 있는 카드를 맨 아래로 옮김 
	}
	
	cout << myqueue.front();
	
	return 0;
}
