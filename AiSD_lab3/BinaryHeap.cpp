#include "Iterator.h"
#include "Stack.h"
#include "Queue.h"
#include <stdexcept>
#include <iostream>


class BinaryHeap{
private:
	int* binary_heap;
	size_t size;
	int capasity;
	int const SIMPLE_CAPASITY = 100;

public:
	BinaryHeap() {
		this->size = 0;
		this->capasity = SIMPLE_CAPASITY;
		this->binary_heap = new int[capasity];
	}
	BinaryHeap(int* binaryHeap, size_t size) {
		this->size = size;
		this->capasity = 2 * size;
		this->binary_heap = new int[capasity];
		for (int i = 0; i < size; i++)
			this->binary_heap[i] = binaryHeap[i];
	}

	class DftIterator : public Iterator {
	private:
		Stack stack;
		int curr_index;
		int* binary_heap;
		size_t size;
		int count_out;
	public:
		DftIterator(int* binary_heap, size_t size) {
			this->size = size;
			this->binary_heap = binary_heap;
			this->curr_index = 0;
		}

		~DftIterator() {
			delete[] binary_heap;
		}

		int next() {
			int temp;
			if (curr_index <= size - 1) {
				temp = binary_heap[curr_index];
				if (2 * curr_index + 2 <= size - 1) {
					stack.push(2 * curr_index + 2);
				}
				curr_index = 2 * curr_index + 1;
			}
			else {
				curr_index = stack.takeLast();
				temp = binary_heap[curr_index];
			}
			count_out++;
			return temp;
		};

		bool has_next() {
			if (curr_index > size - 1 && count_out < size) {
				curr_index = stack.takeLast();
				return has_next();
			}
			return (!stack.isEmpty() || curr_index <= size - 1 && count_out < size);
		}

	};

	class BftIterator : public Iterator {
	private:
		Queue queue;
		int* binary_heap;
		size_t size;
		int curr_index;
	public:

		BftIterator(int* binary_heap, size_t size) {
			this->size = size;
			this->binary_heap = binary_heap;
			this->curr_index = 0;
			queue.push(this->binary_heap[curr_index]);
		}

		~BftIterator() {
			delete[] binary_heap;
		};

		int next() {
			if (!has_next())
				throw std::out_of_range::out_of_range("The heap is empty");
			else {
				if ((2 * curr_index + 1) <= size - 1)
					queue.push(binary_heap[2 * curr_index + 1]);
				if ((2 * curr_index + 2) <= size - 1)
					queue.push(binary_heap[2 * curr_index + 2]);
				curr_index++;
				return queue.takeTop();
			}
		};
		bool has_next() {
			return !queue.isEmpty();
		}
	};

	~BinaryHeap() {
		delete[] binary_heap;
	}

	int getSize() {
		return size;
	}

	int at(int index) {
		if (index >= size) {
			throw std::out_of_range::out_of_range("The index is out of range");
		}
		else
			return binary_heap[index];
		std::cout << index;
	}

	void deleteTheLastLeaf() {
		if (size == 0) {
			throw std::out_of_range::out_of_range("The heap is empty");
		}
		else
			size--;
	}

	void addTheLeaf(int value) {
		if (size >= capasity) {
			int* buff = binary_heap;
			capasity += SIMPLE_CAPASITY;
			binary_heap = new int[capasity];
			for (int i = 0; i < size; i++)
				binary_heap[i] = buff[i];
			delete[] buff;
		}
		binary_heap[size] = value;
		size++;
	}

	void print() {
		Iterator* iterator = create_bft_iterator();
		/*for (int i = 0; i < getSize(); i++)
			std::cout << at(i) << ' ';*/
		while (iterator->has_next())
			std::cout << iterator->next()<<" ";
		std::cout << std::endl;
	}

	Iterator* create_bft_iterator() {
		return new BftIterator(this->binary_heap, size);
	};

	Iterator* create_dft_iterator() {
		return new DftIterator(this->binary_heap, size);
	}

	void insert(int value) {
		if (size >= capasity) {
			int* buff = binary_heap;
			capasity += SIMPLE_CAPASITY;
			binary_heap = new int[capasity];
			for (int i = 0; i < size; i++)
				binary_heap[i] = buff[i];
			delete[] buff;
		}
		binary_heap[size] = value;
		size++;
		if (size > 0) {
			int curr_index = size - 1;
			int par_index = (curr_index - 1) / 2;
			while ((curr_index > 0) && (binary_heap[par_index] < binary_heap[curr_index])) {
				int buff = binary_heap[par_index];
				binary_heap[par_index] = binary_heap[curr_index];
				binary_heap[curr_index] = buff;
				curr_index = par_index;
				par_index = (curr_index - 1) / 2;
			}
		}
	}

};



