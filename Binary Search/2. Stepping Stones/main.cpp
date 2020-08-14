#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long getRocksToBeRemoved(int distance, vector<int> rocks, int mid){
	int len = rocks.size();
	int pos = -1; // 제거되지 않고 징검다리로 놓일 바위의 마지막 위치 
	int gap = 0;  // pos 바위와 i번째 바위의 갭 
	long long removedRocks = 0;
	for(int i = 0; i <= len; i++){
		if(pos == -1) gap = rocks[i]; // 아직 어떤 바위도 살펴보지 않았다면 gap은 시작 위치와 첫번째 바위의 거리 
		else if(i == len) gap = distance - rocks[pos]; // 마지막 바위까지 전부 살펴봤다면 gap은 도착 위치와 pos 바위의 거리 
		else gap = rocks[i] - rocks[pos]; // gap은 pos 바위와 i번째 바위가 떨어진 거리 
		// pos 위치의 바위와 현재 바위 사이의 거리가 mid 미만으로 떨어져 있다면 현재 바위를 제거함
		if(gap < mid) removedRocks++;
		// pos 위치의 바위와 현재 바위 사이의 거리가 mid 이상 혹은 mid만큼 떨어져 있다면 pos를 현재 바위로 옮김 
		else pos = i;
	}	
	return removedRocks;
}

long long solution(int distance, vector<int> rocks, int n) {
    long long answer = 0;
    long long l = 0;
    long long r = distance;
    long long mid; // 돌이 서로 떨어진 거리의 최소값 
	long long cnt;
	
	// 벡터를 정렬
	sort(rocks.begin(), rocks.end()); 
	
	while(l <= r){
		mid = (l + r) / 2;
		cnt = getRocksToBeRemoved(distance, rocks, mid); // 현재 최소값(mid)을 얻기 위해서 몇 개의 돌을 없애야 하는지  
		if(cnt > n){
			// 돌을 n개보다 더 많이 없애야 한다면 최소값을 낮춤 (상한을 내림)
			r = mid - 1;			
		} 
		else {
			// 돌을 n개보다 덜 없애도 된다면 최소값을 올려봄 (하한을 올림)
			answer = mid;
			l = mid + 1;
		}
	}
    
    return answer;
}

int main(int argc, char** argv) {
	
	vector<int> rocks = {2, 14, 11, 21, 17};
	cout << solution(25, rocks, 2);	
	
	return 0;
}
