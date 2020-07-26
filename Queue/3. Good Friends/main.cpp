#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 300001
#define NAMEMAX 21

using namespace std;

int main(int argc, char** argv) {
	
	int n, k, len;
	long long result = 0;
	string tempStr;
	queue<int> names[NAMEMAX]; // 큐는 캐싱의 역할 
	
	cin >> n;
	cin >> k;
	cin.ignore();
	
	// 앞 등수부터 오른쪽으로만 살펴봄 
	for(int i = 0; i < n; i++){
		getline(cin, tempStr);
		len = tempStr.size();
		// 이름 길이에 해당하는 큐가 비어있지 않을 경우 : k 이하로 차이나는 학생이 있는지 탐색
		// 등수가 k 이상으로 차이나는 동안 pop 
		while(!names[len].empty() && names[len].front() < i - k){
			names[len].pop();
		}
		// 큐에 남아있는 원소들은 k 이하로 차이나는 학생들일 것임
		result = result + names[len].size();	
		// 자기 자신을 스택에 push
		names[len].push(i);	
	} 
	
	cout << result << "\n";
	
	return 0;
}
