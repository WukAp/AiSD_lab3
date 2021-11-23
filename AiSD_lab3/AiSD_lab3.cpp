#include "BinaryHeap.h"
#include <iostream>
#include "Iterator.h"


int main() {
	BinaryHeap heap;
	heap.insert(10);
	heap.insert(9);
	heap.insert(8);
	heap.insert(7);
	heap.insert(6);
	heap.insert(5);
	heap.insert(4);
	heap.insert(3);
	heap.insert(2);
	heap.insert(1);
	heap.insert(0);

	std::cout << "creating the binary heap with 0..10 values\n";

	{
		Iterator* bft_iterator = heap.create_bft_iterator();
		std::cout << "traversing the graph in width: \n";
		while (bft_iterator->has_next())
			std::cout << bft_iterator->next() << ' ';
		std::cout << std::endl;

		Iterator* dft_iterator = heap.create_dft_iterator();
		std::cout << "traversing the graph in depth: \n";
		while (dft_iterator->has_next())
			std::cout << dft_iterator->next() << ' ';
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "is the value 0 in the graph? - "<< (heap.ñontains(0)?"yes":"no") << "\n";
	std::cout << "is the value 1 in the graph? - "<< (heap.ñontains(1)?"yes":"no") << "\n";
	std::cout << "is the value 2 in the graph? - "<< (heap.ñontains(2)?"yes":"no") << "\n";
	std::cout << "is the value 3 in the graph? - "<< (heap.ñontains(3)?"yes":"no") << "\n";
	std::cout << "is the value 4 in the graph? - "<< (heap.ñontains(4)?"yes":"no") << "\n";
	std::cout << "is the value 5 in the graph? - "<< (heap.ñontains(5)?"yes":"no") << "\n";
	std::cout << "is the value 6 in the graph? - "<< (heap.ñontains(6)?"yes":"no") << "\n";
	std::cout << "is the value 7 in the graph? - "<< (heap.ñontains(7)?"yes":"no") << "\n";
	std::cout << "is the value 8 in the graph? - "<< (heap.ñontains(8)?"yes":"no") << "\n";
	std::cout << "is the value 9 in the graph? - "<< (heap.ñontains(9)?"yes":"no") << "\n";
	std::cout << "is the value 10 in the graph? - "<< (heap.ñontains(10)?"yes":"no") << "\n";
	std::cout << "is the value -1 in the graph? - "<< (heap.ñontains(-1)?"yes":"no") << "\n";
	std::cout << std::endl;

	std::cout << "adding value 5 to the graph...\n";
	heap.insert(5);
	{
		Iterator* bft_iterator = heap.create_bft_iterator();
		std::cout << "traversing the graph in width: \n";
		while (bft_iterator->has_next())
			std::cout << bft_iterator->next() << ' ';
		std::cout << std::endl;

		Iterator* dft_iterator = heap.create_dft_iterator();
		std::cout << "traversing the graph in depth: \n";
		while (dft_iterator->has_next())
			std::cout << dft_iterator->next() << ' ';
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "adding value 8 to the graph...\n";
	heap.insert(8);
	{
		Iterator* bft_iterator = heap.create_bft_iterator();
		std::cout << "traversing the graph in width: \n";
		while (bft_iterator->has_next())
			std::cout << bft_iterator->next() << ' ';
		std::cout << std::endl;

		Iterator* dft_iterator = heap.create_dft_iterator();
		std::cout << "traversing the graph in depth: \n";
		while (dft_iterator->has_next())
			std::cout << dft_iterator->next() << ' ';
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "removing a value 5 from the graph...\n";
	heap.remove(5);
	{
		Iterator* bft_iterator = heap.create_bft_iterator();
		std::cout << "traversing the graph in width: \n";
		while (bft_iterator->has_next())
			std::cout << bft_iterator->next() << ' ';
		std::cout << std::endl;

		Iterator* dft_iterator = heap.create_dft_iterator();
		std::cout << "traversing the graph in depth: \n";
		while (dft_iterator->has_next())
			std::cout << dft_iterator->next() << ' ';
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "removing a value 8 from the graph...\n";
	heap.remove(8);
	{
		Iterator* bft_iterator = heap.create_bft_iterator();
		std::cout << "traversing the graph in width: \n";
		while (bft_iterator->has_next())
			std::cout << bft_iterator->next() << ' ';
		std::cout << std::endl;

		Iterator* dft_iterator = heap.create_dft_iterator();
		std::cout << "traversing the graph in depth: \n";
		while (dft_iterator->has_next())
			std::cout << dft_iterator->next() << ' ';
	}
}