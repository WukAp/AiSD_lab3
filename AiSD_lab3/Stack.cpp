// class stack for depth-first traverse in BinaryHeap
#include <cstddef>
#include <stdexcept>
#include <iostream>
class Stack {
private:
	class Node {//node of the stack
	public:
		int value;
		Node* prev;
		Node(int value) { 
			this->value = value;
			prev = NULL;
		}
	};
	Node* last;
	size_t size;
public:
	// constructor of the Stack
	Stack() {
		last = NULL;
		size = 0;
	}
	// destructor of the Stack
	~Stack() {
		while (!isEmpty())
			takeLast();
	}
	//push the last node
	void push(int value) {
		Node* buff = last;
		last = new Node(value);
		last->prev = buff;
		size++;
	}
	//return the last node of the stack and delete them
	int takeLast()	{
		if (isEmpty())
			throw std::out_of_range("The stack is empty");
		else{
			int last_value = last->value;
			Node* buff = last->prev;
			delete last;
			last = buff;
			size--;
			return last_value;
		}		
	}
	//is the stack empty
	bool isEmpty()	{
		return (size==0);
	}
	//return the size of the stack
	size_t getSize()	{
		return size;
	}

};