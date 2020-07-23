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
    int time = 1; // ������ �ð�
    int index = 0; // ���� ���;� �ϴ� Ʈ���� ��ȣ
    int current_weight = 0;
    queue<Node> myqueue; // the time when trucks arrive at the bridge

    while(true){
        // ť���� ������ �ϴ� Ʈ���� �ִ��� Ȯ��
        if(!myqueue.empty() && myqueue.front().time + bridge_length == time){
            current_weight -= myqueue.front().weight;
            myqueue.pop();
        }
        // ť�� ���� �� �ִ� Ʈ���� �ִ��� Ȯ��
        if(index < truck_weights.size() && current_weight + truck_weights[index] <= weight){
            Node newNode(time, truck_weights[index]);
            myqueue.push(newNode);
            current_weight += truck_weights[index++];
        }
        // �ٸ� ���� �ƹ� Ʈ���� ���� ��⿭�� ���ٸ� ����
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

