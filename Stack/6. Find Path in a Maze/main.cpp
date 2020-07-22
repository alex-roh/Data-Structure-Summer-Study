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
	// ��, ��, ��, �Ͽ� ���� ��带 ����
	Node *east;
	Node *west;
	Node *south;
	Node *north;
	
	// ��->��->��->������ �̵��ϱ� ���� ��->��->��->�� ������ push 
	if(col != 15) {east = new Node(row, col + 1); mystack.push(*east);} // ��: col + 1	
	if(col != 0) {west = new Node(row, col - 1); mystack.push(*west);} // ��: col - 1 
	if(row != 15) {south = new Node(row + 1, col); mystack.push(*south);} // ��: row + 1 
	if(row != 0) {north = new Node(row - 1, col); mystack.push(*north);} // ��: row - 1		
}
 
int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::stack<Node> mystack;
	int temp, maze[16][16] = {0};
	bool flag = false;
	Node next(0, 0); 

	// �̷��� �������� ���õ� ����
	int s_row = 0, s_col = 0; 
	
	// ���� �̷��� ��ġ�� ���õ� ����
	int row = 0, col = 0; 
	
	freopen("input.txt", "r", stdin);
	
	// �׽�Ʈ ���̽� 10���� ���� �ݺ��� 
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
		
		// ���� ��ġ�� ���������� ������
		row = s_row; col = s_col; 
		Node start(row, col);
		mystack.push(start);
		
		// ������ ���� ���� ���� �ݺ�
		while(!mystack.empty()){
			// ���ÿ��� �̵��� �� �ϳ��� ����
			next.x = mystack.top().x;
			next.y = mystack.top().y;
			mystack.pop();
			//cout << "(" << next.x << ", " << next.y << ")" << "�� �˻��մϴ�. : " << maze[next.x][next.y] <<endl; 
			// 1. �̹� ������ ���̰ų� ���� ��� 
			if(maze[next.x][next.y] == VISITED || maze[next.x][next.y] == 1){
				//cout << "(" << next.x << ", " << next.y << ")�� " << "�� �� ���� ���Դϴ�." << endl; 
			}
			// 2. ������ �� �ִ� ���� ��� 
			else if(maze[next.x][next.y] == 0 || maze[next.x][next.y] == 2){
				//cout << "(" << next.x << ", " << next.y << ")�� " << "������ �� �ִ� ���Դϴ�." << endl; 
				row = next.x; col = next.y;
				move(mystack, row, col);
				// �̹� ������ ��� ǥ��
				maze[row][col] = VISITED;
			} 
			// 3. �������� ��� 
			else if(maze[next.x][next.y] == 3){
				flag = true;
				break;
			}
		}
		
		// ���� ���
		cout << "#" << test + 1 << " " << flag << endl;
		flag = false;
		
		// ������ �ʱ�ȭ
		clear(mystack);
	}
	
	return 0;
}
