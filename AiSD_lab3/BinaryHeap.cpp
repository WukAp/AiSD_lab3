#include "Iterator.h"
#include "Stack.h"
#include "Queue.h"
#include <stdexcept>

class BinaryHeap{
private:
	int* binary_heap; // array with the leafs
	size_t size; // imaginary size of array
	int capasity; // real size of array
	int const SIMPLE_CAPASITY = 50; // step of capasity

public:
	//iterator for depth-first search
	class DftIterator : public Iterator {
	private:
		int* binary_heap;
		size_t size;
		int curr_index;
		int count_of_passed_node;
		Stack stack;

	public:
		//constructor of the DftIterator
		DftIterator(int* binary_heap, size_t size) {
			this->binary_heap = binary_heap;
			this->size = size;
			this->curr_index = 0;
			this->count_of_passed_node = 0;
		}
		
		//return next node of the graph
		int next() {
			if (!has_next())
				throw std::out_of_range::out_of_range("The heap is empty");
			else {
				int buff;
				if (curr_index <= size - 1) {
					buff = binary_heap[curr_index];
					if (2 * curr_index + 2 <= size - 1)
						stack.push(2 * curr_index + 2);

					curr_index = 2 * curr_index + 1;
				}
				else {
					curr_index = stack.takeLast();
					buff = binary_heap[curr_index];
				}
				count_of_passed_node++;
				if (curr_index > size - 1 && has_next())
					curr_index = stack.takeLast();
				return buff;
			}			
		};
		//is the next value exist
		bool has_next() {
			return  count_of_passed_node < size;
		}
	};
	//iterator for breadth-first search
	class BftIterator : public Iterator {
	private:
		int* binary_heap;
		size_t size;
		int curr_index;
		Queue queue;

	public:
		//constructor of the BftIterator
		BftIterator(int* binary_heap, size_t size) {
			this->binary_heap = binary_heap;
			this->size = size;
			this->curr_index = 0;
			if (size>0)queue.push(this->binary_heap[curr_index]);
		}

		//return next node of the graph
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
		//is the next value exist
		bool has_next() {
			return !queue.isEmpty();
		}
	};
	//constructor of BinaryHeap
	BinaryHeap() {
		this->size = 0;
		this->capasity = SIMPLE_CAPASITY;
		this->binary_heap = new int[capasity];
	}
	// destructor of BinaryHeap
	~BinaryHeap() {
		delete[] binary_heap;
	}
	//return the imaginary size of the binary heap
	int getSize() {
		return size;
	}
	//is binary heap contains the desired value
	bool contains(int desired_value){
		for (int i = 0; i < size; i++)
			if (binary_heap[i] == desired_value) return true;
		return false;		
	}
	//insert the node by value
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
				std::swap(binary_heap[curr_index], binary_heap[par_index]);
				curr_index = par_index;
				par_index = (curr_index - 1) / 2;
			}
		}
	}
	//deletion node with the user's value
	void remove(int value_to_delete) {
		for (int i = 0; i < size; i++) {
			if (binary_heap[i] == value_to_delete) {//finding all nodes with the user's value
				//deletion node
				std::swap(binary_heap[i], binary_heap[size - 1]);
				size--;
				//returning heap properties
				int curr_index = i;
				int kid_index1 = 2 * curr_index + 1;
				int kid_index2 = 2 * curr_index + 2;
				while ((kid_index1 < size) && (binary_heap[curr_index] < binary_heap[kid_index1])
					|| (kid_index2 < size) && (binary_heap[curr_index] < binary_heap[kid_index2])) {

					if ((kid_index2 >= size) || (binary_heap[kid_index2] < binary_heap[kid_index1])) {
						std::swap(binary_heap[curr_index], binary_heap[kid_index1]);
						curr_index = kid_index1;
					}
					else {
						std::swap(binary_heap[curr_index], binary_heap[kid_index2]);
						curr_index = kid_index2;
					}
					kid_index1 = 2 * curr_index + 1;
					kid_index2 = 2 * curr_index + 2;
				}
				return;
			}
		}
		throw std::invalid_argument("The value not found");
	}
	//creating iterator for depth-first search
	Iterator* create_dft_iterator() {
		return new DftIterator(this->binary_heap, size);
	}
	//creating iterator for breadth-first search
	Iterator* create_bft_iterator() {
		return new BftIterator(this->binary_heap, size);
	};
};