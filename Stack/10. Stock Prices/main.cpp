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
        // 스택이 비었거나 스택의 top보다 현재 원소가 더 크거나 같다면 push
        if(mystack.empty() || prices.at(mystack.top()) <= prices.at(i)){
            mystack.push(i);
        }
        else {
	        // 스택의 top보다 현재 원소가 작다면 pop
            while(prices.at(mystack.top()) > prices.at(i)){
                answer[mystack.top()] = i - mystack.top();
                mystack.pop();
            }
            mystack.push(i);
        }
    }
    
    // 스택이 비어있지 않다면 빌 때까지 pop하면서 answer 벡터를 채움
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
