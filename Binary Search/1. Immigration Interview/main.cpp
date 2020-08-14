#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// �ش� �ð� ���� �Ա� �ɻ簡 ������ ����� ���� ���� 
long long possibleNum(vector<int> &times, int pivot){
	long long num = 0;
	for(long long i = 0; i < times.size(); i++){
		num += pivot / times[i];	
	}
	return num;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    // ���� ���� �Ա� �ɻ���� ��� ����� �ɻ��ϴ� ��� 
    long long slowest = n * times.back();
    cout << "slowest = " << slowest << endl;
    // ������ ���� [1 ~ ���� ���� �Ա� �ɻ���� n�� ��θ� �ɻ���] 
    long long l = 1;
    long long r = slowest;
    long long mid = (l + r) / 2;
	long long cnt;
	// �ش� �������� �̺� Ž��
	while(l <= r){
		mid = (l + r) / 2;
		cnt = possibleNum(times, mid); // �ش� �ð� ���� �Ա� �ɻ簡 ������ ����� ��
		cout << "cnt = " << cnt << endl;
		if(n <= cnt){
			// �ش� �ð� ���� n�� Ȥ�� �׺��� �� ���� �ɻ��� �� �ִٸ� �ð��� ���� 
			answer = mid;
			r = mid - 1;
		} 
		else if (n > cnt) {
			// �ش� �ð� ���� n���� �� �ɻ��� �� ���ٸ� �ð��� �ø� 
			l = mid + 1;
		}
	} 
    
    return answer;
}

int main(){
	
	vector<int> times = {3, 8, 3, 6, 9, 2, 4};
	cout << solution(10, times);
	return 0;
}
