#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long getRocksToBeRemoved(int distance, vector<int> rocks, int mid){
	int len = rocks.size();
	int pos = -1; // ���ŵ��� �ʰ� ¡�˴ٸ��� ���� ������ ������ ��ġ 
	int gap = 0;  // pos ������ i��° ������ �� 
	long long removedRocks = 0;
	for(int i = 0; i <= len; i++){
		if(pos == -1) gap = rocks[i]; // ���� � ������ ���캸�� �ʾҴٸ� gap�� ���� ��ġ�� ù��° ������ �Ÿ� 
		else if(i == len) gap = distance - rocks[pos]; // ������ �������� ���� ����ôٸ� gap�� ���� ��ġ�� pos ������ �Ÿ� 
		else gap = rocks[i] - rocks[pos]; // gap�� pos ������ i��° ������ ������ �Ÿ� 
		// pos ��ġ�� ������ ���� ���� ������ �Ÿ��� mid �̸����� ������ �ִٸ� ���� ������ ������
		if(gap < mid) removedRocks++;
		// pos ��ġ�� ������ ���� ���� ������ �Ÿ��� mid �̻� Ȥ�� mid��ŭ ������ �ִٸ� pos�� ���� ������ �ű� 
		else pos = i;
	}	
	return removedRocks;
}

long long solution(int distance, vector<int> rocks, int n) {
    long long answer = 0;
    long long l = 0;
    long long r = distance;
    long long mid; // ���� ���� ������ �Ÿ��� �ּҰ� 
	long long cnt;
	
	// ���͸� ����
	sort(rocks.begin(), rocks.end()); 
	
	while(l <= r){
		mid = (l + r) / 2;
		cnt = getRocksToBeRemoved(distance, rocks, mid); // ���� �ּҰ�(mid)�� ��� ���ؼ� �� ���� ���� ���־� �ϴ���  
		if(cnt > n){
			// ���� n������ �� ���� ���־� �Ѵٸ� �ּҰ��� ���� (������ ����)
			r = mid - 1;			
		} 
		else {
			// ���� n������ �� ���ֵ� �ȴٸ� �ּҰ��� �÷��� (������ �ø�)
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
