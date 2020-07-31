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
	
	// ����
	int time = 0; 
	
	// ���� �ʱ�ȭ
	int board[MAX][MAX] = { NONE };	
	int max; // ������ ���Ѱ�� 
	cin >> max;
	
	// ���� �Ӹ��� ������ ���� ���� ����Ʈ
	list<pair<int, int>> snake; // ���忡���� ��� ���� �� 
	int direction; // ���� ���� 
	
	// ����� ���� 
	int appleNum;
	cin >> appleNum;
	
	// ����� ��ġ�� ���� �迭�� ���� 
	int row, col;
	for(int i = 0; i < appleNum; i++){
		cin >> row;
		cin >> col;
		board[row - 1][col - 1] = APPLE;
	}
	
	// ������ ��ġ�� ���� ���Ḯ��Ʈ
	list<pair<int, char>> turns;
	int turnNum, t;
	char d;
	cin >> turnNum;
	for(int i = 0; i < turnNum; i++){
		cin >> t;
		cin >> d;
		turns.push_back(make_pair(t, d));
	}
	
	// ���� ��ġ �ʱ�ȭ
	snake.push_front(make_pair(0, 0));
	board[0][0] = EXIST;
	direction = 1; // ó���� ������ �������� �̵� 
	
	// ���� �ѹ��� 1�ʿ� �ش��ϴ� �ݺ���
	while(true) {
		
		time++;
		
		// �Ӹ� ��带 ���� ���� 
		pair<int, int> move = make_pair(snake.front().first + card[direction].row,
										snake.front().second + card[direction].col);
							
		// ���� ���� �Ӹ� ��尡 ��踦 ����ų� �ε����� �ʴ´ٸ� 
		if((move.first < max && 0 <= move.first) && (move.second < max && 0 <= move.second) 
			&& board[move.first][move.second] != EXIST){
			
			// �Ӹ� ��带 ����
			snake.push_front(move); 
			
			// ����� ���� ��� 
			if(board[move.first][move.second] != APPLE){
				// ������ �� 
				board[snake.back().first][snake.back().second] = NONE;
				board[move.first][move.second] = EXIST;
				snake.pop_back();
			} 
			// ����� �ִ� ��� 
			else{
				board[move.first][move.second] = EXIST;
			}
			
			// ������ ȸ����Ŵ 
			if(!turns.empty() && turns.front().first == time){
				// ���������� ���� ȸ�� 
				if(turns.front().second == 'D'){
					direction = (direction + 1) % 4;
				}
				else{
					direction = (direction + 3) % 4;
				}
				turns.pop_front();
			}
				
		} 
		// ���� ���� �Ӹ� ��尡 ��踦 ����ų� �ε��� ��� 
		else{
			cout << time << "\n";	
			break;
		} 	
	}
	
	return 0;
}
