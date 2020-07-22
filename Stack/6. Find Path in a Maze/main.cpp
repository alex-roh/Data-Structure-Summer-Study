#include <iostream>
#include <stack>
#include <string>
#include <vector>
#define VISITED 99

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

class Node{
	public:
		int x;
		int y;
	Node(int a, int b){
		x = a; y = b;
	}
};

template<typename T>
void clear( std::stack<T> &q )
{
   stack<T> empty;
   swap(q, empty);
}

template<typename T>
void move(stack<T> &mystack, int row, int col)
{
	// 동, 서, 남, 북에 대한 노드를 생성
	Node *east;
	Node *west;
	Node *south;
	Node *north;
	
	// 동->서->남->북으로 이동하기 위해 북->남->서->동 순으로 push 
	if(col != 15) {east = new Node(row, col + 1); mystack.push(*east);} // 동: col + 1	
	if(col != 0) {west = new Node(row, col - 1); mystack.push(*west);} // 서: col - 1 
	if(row != 15) {south = new Node(row + 1, col); mystack.push(*south);} // 남: row + 1 
	if(row != 0) {north = new Node(row - 1, col); mystack.push(*north);} // 북: row - 1		
}
 
int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::stack<Node> mystack;
	int temp, maze[16][16] = {0};
	bool flag = false;
	Node next(0, 0); 

	// 미로의 시작점과 관련된 변수
	int s_row = 0, s_col = 0; 
	
	// 현재 미로의 위치와 관련된 변수
	int row = 0, col = 0; 
	
	freopen("input.txt", "r", stdin);
	
	// 테스트 케이스 10개에 대한 반복문 
	for(int test = 0; test < 10; test++){
		
		scanf("%d", &temp);
		for(int i = 0; i < 16; i++){
			for(int j = 0; j < 16; j++){
				scanf("%1d", &maze[i][j]);
				if(maze[i][j] == 2){
					s_row = i; s_col = j;
				}
			}
		}
		
		// 현재 위치를 시작점으로 세팅함
		row = s_row; col = s_col; 
		Node start(row, col);
		mystack.push(start);
		
		// 스택이 비지 않은 동안 반복
		while(!mystack.empty()){
			// 스택에서 이동할 곳 하나를 꺼냄
			next.x = mystack.top().x;
			next.y = mystack.top().y;
			mystack.pop();
			//cout << "(" << next.x << ", " << next.y << ")" << "을 검사합니다. : " << maze[next.x][next.y] <<endl; 
			// 1. 이미 지나간 길이거나 벽인 경우 
			if(maze[next.x][next.y] == VISITED || maze[next.x][next.y] == 1){
				//cout << "(" << next.x << ", " << next.y << ")는 " << "갈 수 없는 길입니다." << endl; 
			}
			// 2. 지나갈 수 있는 길인 경우 
			else if(maze[next.x][next.y] == 0 || maze[next.x][next.y] == 2){
				//cout << "(" << next.x << ", " << next.y << ")는 " << "지나갈 수 있는 길입니다." << endl; 
				row = next.x; col = next.y;
				move(mystack, row, col);
				// 이미 지나간 길로 표시
				maze[row][col] = VISITED;
			} 
			// 3. 목적지인 경우 
			else if(maze[next.x][next.y] == 3){
				flag = true;
				break;
			}
		}
		
		// 정답 출력
		cout << "#" << test + 1 << " " << flag << endl;
		flag = false;
		
		// 스택을 초기화
		clear(mystack);
	}
	
	return 0;
}
