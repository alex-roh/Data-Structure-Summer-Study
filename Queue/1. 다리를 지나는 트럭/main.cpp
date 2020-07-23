#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node{
    public:
        int time;
        int weight;
        Node(int x, int y){
            time = x;
            weight = y;
        }
};

#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node{
    public:
        int time;
        int weight;
        Node(int x, int y){
            time = x;
            weight = y;
        }
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 1; // 지나간 시간
    int index = 0; // 현재 들어와야 하는 트럭의 번호
    int current_weight = 0;
    queue<Node> myqueue; // the time when trucks arrive at the bridge

    while(true){
        // 큐에서 나가야 하는 트럭이 있는지 확인
        if(!myqueue.empty() && myqueue.front().time + bridge_length == time){
            current_weight -= myqueue.front().weight;
            myqueue.pop();
        }
        // 큐에 들어올 수 있는 트럭이 있는지 확인
        if(index < truck_weights.size() && current_weight + truck_weights[index] <= weight){
            Node newNode(time, truck_weights[index]);
            myqueue.push(newNode);
            current_weight += truck_weights[index++];
        }
        // 다리 위에 아무 트럭도 없고 대기열도 없다면 종료
        if(myqueue.empty() && index == truck_weights.size()) break;

        time++;
    }

    return time;
}


int main(){
	
	int bridge_length = 100;
	int weight = 100;
	vector<int> truck_weights = {10,10,10,10,10,10,10,10,10,10};
	
	int time = solution(bridge_length, weight, truck_weights);
	
	cout << time << endl;
	
	return 0;
}

