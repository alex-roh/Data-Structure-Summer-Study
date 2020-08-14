#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0, standard = 0, len = citations.size();
    
    // �������� ����
    sort(citations.begin(), citations.end(), greater<int>());
    
    // ���� ó��
    if(citations.front() == 0) return 0;
    
    for(int i = 0; i < len; i++){
        
        // answer�� �̻� �ο�� ���� answer�� �̻��� ���
        if(answer < citations.at(i)){
           answer++; 
        }
        
    }
    
    return answer;
}
