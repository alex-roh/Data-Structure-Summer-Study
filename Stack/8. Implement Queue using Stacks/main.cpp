#include <iostream>
#include <stack>

using namespace std;

// Implement Queue using Stacks

template<typename T>
T dequeue(stack<T> &s){
	T element;
	stack<T> temp;
	s.swap(temp);
	
	while(!temp.empty()){
		element = temp.top();
		temp.pop();
	}
	
	// back to original
	temp.swap(s);
	
	// the last element is the newest element
	return element;
}

template<typename T>
void enqueue(stack<T> &s, T element){
	s.push(element);
	return;
}


int main(int argc, char** argv) {

	stack<int> mystack;
	
	// test enqueue
	enqueue(mystack, 5);
	enqueue(mystack, 10);
	cout << mystack.top() << endl;
	
	// test dequeue
	dequeue(mystack);
	cout << mystack.top() << endl;

	return 0;
}
