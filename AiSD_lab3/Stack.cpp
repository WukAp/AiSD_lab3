// class stack for depth-first traverse in BinaryHeap
#include <cstddef>
#include <stdexcept>
#include <iostream>
class Stack {
private:

	class Node {
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

	Stack() {
		last = NULL;
		size = 0;
	}


	~Stack() {
		while (!isEmpty())
			takeLast();
	}


	void push(int value) {
		Node* buff = last;
		last = new Node(value);
		last->prev = buff;
		size++;
	}


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



	bool isEmpty()	{
		return (size==0);
	}


	size_t getSize()	{
		return size;
	}

	void print() {
		if (size == 0)
			std::cout << "The stack is empty";
		else {
			Node* buff = last;

			while (buff != NULL) {
				std::cout << buff->value << ' ';
				buff = buff->prev;
			}
		}
		std::cout << std::endl;
	}
};