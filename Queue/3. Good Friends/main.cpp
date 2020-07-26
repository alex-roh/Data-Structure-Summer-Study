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
	queue<int> names[NAMEMAX]; // ť�� ĳ���� ���� 
	
	cin >> n;
	cin >> k;
	cin.ignore();
	
	// �� ������� ���������θ� ���캽 
	for(int i = 0; i < n; i++){
		getline(cin, tempStr);
		len = tempStr.size();
		// �̸� ���̿� �ش��ϴ� ť�� ������� ���� ��� : k ���Ϸ� ���̳��� �л��� �ִ��� Ž��
		// ����� k �̻����� ���̳��� ���� pop 
		while(!names[len].empty() && names[len].front() < i - k){
			names[len].pop();
		}
		// ť�� �����ִ� ���ҵ��� k ���Ϸ� ���̳��� �л����� ����
		result = result + names[len].size();	
		// �ڱ� �ڽ��� ���ÿ� push
		names[len].push(i);	
	} 
	
	cout << result << "\n";
	
	return 0;
}
