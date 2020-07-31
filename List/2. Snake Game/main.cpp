#include <iostream>
#include <list>
#include <utility>
#define MAX 101
#define NONE 0
#define EXIST 1
#define APPLE 2

using namespace std;

typedef struct{
	int row;
	int col;
} Dir;

Dir card[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // N E S W

int main(int argc, char** argv) {
	
	// 정답
	int time = 0; 
	
	// 보드 초기화
	int board[MAX][MAX] = { NONE };	
	int max; // 보드의 상한경계 
	cin >> max;
	
	// 뱀의 머리와 몸통을 담은 연결 리스트
	list<pair<int, int>> snake; // 보드에서의 행과 열이 들어감 
	int direction; // 뱀의 방향 
	
	// 사과의 개수 
	int appleNum;
	cin >> appleNum;
	
	// 사과의 위치를 보드 배열에 저장 
	int row, col;
	for(int i = 0; i < appleNum; i++){
		cin >> row;
		cin >> col;
		board[row - 1][col - 1] = APPLE;
	}
	
	// 방향의 위치를 담은 연결리스트
	list<pair<int, char>> turns;
	int turnNum, t;
	char d;
	cin >> turnNum;
	for(int i = 0; i < turnNum; i++){
		cin >> t;
		cin >> d;
		turns.push_back(make_pair(t, d));
	}
	
	// 뱀의 위치 초기화
	snake.push_front(make_pair(0, 0));
	board[0][0] = EXIST;
	direction = 1; // 처음은 오른쪽 방향으로 이동 
	
	// 루프 한번이 1초에 해당하는 반복문
	while(true) {
		
		time++;
		
		// 머리 노드를 새로 만듦 
		pair<int, int> move = make_pair(snake.front().first + card[direction].row,
										snake.front().second + card[direction].col);
							
		// 새로 만든 머리 노드가 경계를 벗어나거나 부딪히지 않는다면 
		if((move.first < max && 0 <= move.first) && (move.second < max && 0 <= move.second) 
			&& board[move.first][move.second] != EXIST){
			
			// 머리 노드를 붙임
			snake.push_front(move); 
			
			// 사과가 없는 경우 
			if(board[move.first][move.second] != APPLE){
				// 꼬리를 뗌 
				board[snake.back().first][snake.back().second] = NONE;
				board[move.first][move.second] = EXIST;
				snake.pop_back();
			} 
			// 사과가 있는 경우 
			else{
				board[move.first][move.second] = EXIST;
			}
			
			// 방향을 회전시킴 
			if(!turns.empty() && turns.front().first == time){
				// 오른쪽으로 방향 회전 
				if(turns.front().second == 'D'){
					direction = (direction + 1) % 4;
				}
				else{
					direction = (direction + 3) % 4;
				}
				turns.pop_front();
			}
				
		} 
		// 새로 만든 머리 노드가 경계를 벗어나거나 부딪힌 경우 
		else{
			cout << time << "\n";	
			break;
		} 	
	}
	
	return 0;
}
