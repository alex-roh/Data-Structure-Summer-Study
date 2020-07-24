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
    
    // progresses ������ �ε����� �������� ����(top���� �켱������ ���� ���� ���Ұ� �� �� �ְ� ��)
    for(int i = progresses.size() - 1; i >= 0; i--){
        mystack.push(i);
    }
    
    // ���� �� ���� �Ϸ翡 �ش���
    while(!mystack.empty()){
        // ��� ����
        for(int i = 0; i < progresses.size(); i++){
            progresses.at(i) += speeds.at(i);
        }
        // ������ �� ���� �ִ� �༮���� ������ �� �ִ��� ���캽
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
