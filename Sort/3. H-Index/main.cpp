#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0, standard = 0, len = citations.size();
    
    // 내림차순 정렬
    sort(citations.begin(), citations.end(), greater<int>());
    
    // 예외 처리
    if(citations.front() == 0) return 0;
    
    for(int i = 0; i < len; i++){
        
        // answer번 이상 인용된 논문이 answer편 이상인 경우
        if(answer < citations.at(i)){
           answer++; 
        }
        
    }
    
    return answer;
}
