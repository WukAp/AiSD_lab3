#include <cstddef>
#include <stdexcept>
#include <iostream>

class Queue {
private:

	class Node	{
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

	Queue() {
		last = first = NULL;
		size = 0;
	}


	~Queue() {
		while (size > 0) {
			takeTop();
		}
	}


	void push(int value) {
		if (size == 0)
			last = first = new Node(value);
		else
			last = last->next = new Node (value);
		size++;
	}


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


	size_t getSize() {
		return size;
	}


	bool isEmpty() {
		return (size == 0);
	}

	void print() {
		if (size == 0)
			std::cout << "The queue is empty";
		else {
			Node* buff = first;

			while (buff != NULL) {
				std::cout << buff->value << ' ';
				buff = buff->next;
			}
		}
		std::cout << std::endl;
	}
};