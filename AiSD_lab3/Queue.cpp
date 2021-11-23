#include <cstddef>
#include <stdexcept>
#include <iostream>

class Queue {
private:
	class Node	{//node of the queue
	public:
		int value;
		Node* next;
		Node(int value=0) {
			this->value = value;
			next = NULL;
		}
	};
	int size;
	Node* first;
	Node* last;
public:
	// constructor of the Queue
	Queue() {
		last = first = NULL;
		size = 0;
	}
	// destructor of the Queue
	~Queue() {
		while (size > 0) {
			takeTop();
		}
	}
	//push the last node
	void push(int value) {
		if (size == 0)
			last = first = new Node(value);
		else
			last = last->next = new Node (value);
		size++;
	}
	//return the first node of the queue and delete them
	int takeTop() {
		if (isEmpty())
			throw std::out_of_range::out_of_range("The queue is empty");
		else {
			int top_value = first->value;
			Node* buff = first->next;
			delete first;
			first = buff;
			size--;
			return top_value;
		}
	}
	//return the size of the queue
	size_t getSize() {
		return size;
	}
	//is the queue empty
	bool isEmpty() {
		return (size == 0);
	}
};