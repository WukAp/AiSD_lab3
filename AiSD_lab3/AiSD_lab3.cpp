#include "BinaryHeap.h"
#include <iostream>
#include "Stack.h"
#include "Queue.h"


int main() {

	BinaryHeap heap;
	heap.insert(5);
	heap.insert(3);
	heap.insert(4);
	heap.insert(9);
	heap.insert(2);
	heap.insert(3);
	heap.insert(6);
	heap.insert(61);
	heap.insert(63);
	heap.insert(65);
	heap.insert(62);

	heap.insert(2);
	heap.insert(7);
	heap.print();

	heap.remove(65);
	heap.print();
	std::cout << heap.�ontains(61)<<std::endl;
	std::cout << heap.�ontains(62)<<std::endl;
	std::cout << heap.�ontains(630)<<std::endl;
	std::cout << heap.�ontains(7)<<std::endl;
	std::cout << heap.�ontains(20)<<std::endl;
	std::cout << heap.�ontains(10)<<std::endl;
}