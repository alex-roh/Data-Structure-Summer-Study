#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 해당 시간 동안 입국 심사가 가능한 사람의 수를 구함 
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
    // 가장 느린 입국 심사관이 모든 사람을 심사하는 경우 
    long long slowest = n * times.back();
    cout << "slowest = " << slowest << endl;
    // 가능한 구간 [1 ~ 가장 느린 입국 심사관이 n명 모두를 심사함] 
    long long l = 1;
    long long r = slowest;
    long long mid = (l + r) / 2;
	long long cnt;
	// 해당 구간에서 이분 탐색
	while(l <= r){
		mid = (l + r) / 2;
		cnt = possibleNum(times, mid); // 해당 시간 동안 입국 심사가 가능한 사람의 수
		cout << "cnt = " << cnt << endl;
		if(n <= cnt){
			// 해당 시간 동안 n명 혹은 그보다 더 많이 심사할 수 있다면 시간을 줄임 
			answer = mid;
			r = mid - 1;
		} 
		else if (n > cnt) {
			// 해당 시간 동안 n명을 다 심사할 수 없다면 시간을 늘림 
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
