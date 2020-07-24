#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> mystack;
    
    int i;
    for(i = 0; i < prices.size(); i++){
        // ������ ����ų� ������ top���� ���� ���Ұ� �� ũ�ų� ���ٸ� push
        if(mystack.empty() || prices.at(mystack.top()) <= prices.at(i)){
            mystack.push(i);
        }
        else {
	        // ������ top���� ���� ���Ұ� �۴ٸ� pop
            while(prices.at(mystack.top()) > prices.at(i)){
                answer[mystack.top()] = i - mystack.top();
                mystack.pop();
            }
            mystack.push(i);
        }
    }
    
    // ������ ������� �ʴٸ� �� ������ pop�ϸ鼭 answer ���͸� ä��
    while(!mystack.empty()){
         answer[mystack.top()] = prices.size() - 1 - mystack.top();
         cout << "result: index = " << mystack.top() << ", value = " << answer[mystack.top()] << "\n";
		 mystack.pop();
    }

    return answer;
}

int main(int argc, char** argv) {
	
	vector<int> prices = {1, 2, 3, 2, 3};
	vector<int> answers = solution(prices);
	
	for(int i = 0; i < prices.size(); i++){
		cout << answers.at(i) << " ";
	}
	
	return 0;
}
