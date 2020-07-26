#include <iostream>
#include <bits/stdc++.h> 

class Node{
	public:
		int value;
		Node *prev;
		Node *next;
		// Constructor
		Node(): prev(nullptr), next(nullptr){}
		Node(int x, Node *y, Node *z): value(x), prev(y), next(z){}
};

class Deque{
	Node *front;
	Node *rear;
		
};

int main(int argc, char** argv) {
	
	
	
	return 0;
}
