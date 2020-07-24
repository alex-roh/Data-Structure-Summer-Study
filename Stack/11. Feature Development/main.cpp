#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int index = 0;
    vector<int> answer;
    stack<int> mystack;
    
    // progresses 벡터의 인덱스를 스택으로 만듦(top에는 우선순위가 제일 높은 원소가 올 수 있게 함)
    for(int i = progresses.size() - 1; i >= 0; i--){
        mystack.push(i);
    }
    
    // 루프 한 번은 하루에 해당함
    while(!mystack.empty()){
        // 기능 개발
        for(int i = 0; i < progresses.size(); i++){
            progresses.at(i) += speeds.at(i);
        }
        // 스택의 맨 위에 있는 녀석부터 배포될 수 있는지 살펴봄
        if(!mystack.empty() && progresses.at(mystack.top()) >= 100){
        	cout << "top = " << mystack.top() << "\n";
            while(!mystack.empty() && progresses.at(mystack.top()) >= 100){
                mystack.pop();
                answer.at(index) += 1;
            }
            index++;
        }
    }
    
    return answer;
}

int main(){
	
	vector<int> answer;
	vector<int> progresses = {93, 30, 55};
	vector<int> speeds = {1, 30, 5};
	
	answer = solution(progresses, speeds);
	
	for(int i = 0; i < answer.size(); i++){
		cout << answer.at(i) << " ";
	}
	
	return 0;
}
