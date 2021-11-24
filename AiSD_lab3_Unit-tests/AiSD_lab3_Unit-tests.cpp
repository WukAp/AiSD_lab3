#include "pch.h"
#include "CppUnitTest.h"
#include "../AiSD_lab3/BinaryHeap.h"
#include "../AiSD_lab3/Iterator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AiSDlab3Unittests
{
	TEST_CLASS(AiSDlab3Unittests) {
	public:		
		TEST_METHOD(insertTest) {
			BinaryHeap heap;
			heap.insert(2);
			heap.insert(3);
			heap.insert(0);
			heap.insert(-1);


			Iterator* bft_iterator = heap.create_bft_iterator();
			Assert::IsTrue(bft_iterator->next() == 3);
			int next_value = bft_iterator->next();
			Assert::IsTrue(next_value == 0 || next_value == 2);
			next_value = bft_iterator->next();
			Assert::IsTrue(next_value == 0 || next_value == 2);
			Assert::IsTrue(next_value >= bft_iterator->next());
		}
		TEST_METHOD(containsTest) {
			BinaryHeap heap;
			heap.insert(2);
			heap.insert(3);
			heap.insert(0);
			heap.insert(-1);

			Assert::IsTrue(heap.contains(-1));
			Assert::IsTrue(heap.contains(0));
			Assert::IsTrue(heap.contains(2));
			Assert::IsTrue(heap.contains(3));
			Assert::IsTrue(!heap.contains(1));
			Assert::IsTrue(!heap.contains(10));
		}
		TEST_METHOD(removeTest) {
			BinaryHeap heap;
			heap.insert(2);
			heap.insert(3);
			heap.insert(0);
			heap.insert(1);

			Assert::IsTrue(heap.contains(1));
			Assert::IsTrue(heap.contains(0));
			Assert::IsTrue(heap.contains(2));
			Assert::IsTrue(heap.contains(3));

			heap.remove(1);
			Assert::IsTrue(!heap.contains(1));
			Assert::IsTrue(heap.contains(0));
			Assert::IsTrue(heap.contains(2));
			Assert::IsTrue(heap.contains(3));

			heap.remove(0);
			Assert::IsTrue(!heap.contains(1));
			Assert::IsTrue(!heap.contains(0));
			Assert::IsTrue(heap.contains(2));
			Assert::IsTrue(heap.contains(3));

			heap.remove(2);
			Assert::IsTrue(!heap.contains(1));
			Assert::IsTrue(!heap.contains(0));
			Assert::IsTrue(!heap.contains(2));
			Assert::IsTrue(heap.contains(3));

			heap.remove(3);
			Assert::IsTrue(!heap.contains(1));
			Assert::IsTrue(!heap.contains(0));
			Assert::IsTrue(!heap.contains(2));
			Assert::IsTrue(!heap.contains(3));
		}
		TEST_METHOD(create_bft_iteratorTest) {
			BinaryHeap heap;
			heap.insert(5);
			heap.insert(4);
			heap.insert(3);
			heap.insert(2);
			heap.insert(1);
			heap.insert(0);

			Iterator* bft_iterator = heap.create_bft_iterator();

			int i = 5;
			while (bft_iterator->has_next()) {
				Assert::IsTrue(bft_iterator->next() == i--);
			}
			Assert::IsTrue(i == -1);
		}
		TEST_METHOD(create_dft_iteratorTest) {
			BinaryHeap heap;
			heap.insert(5);
			heap.insert(4);
			heap.insert(3);
			heap.insert(2);
			heap.insert(1);
			heap.insert(0);

			Iterator* dft_iterator = heap.create_dft_iterator();
			Assert::IsTrue(dft_iterator->has_next());
			Assert::IsTrue(dft_iterator->next() == 5);
			Assert::IsTrue(dft_iterator->has_next());
			Assert::IsTrue(dft_iterator->next() == 4);
			Assert::IsTrue(dft_iterator->has_next());
			Assert::IsTrue(dft_iterator->next() == 2);
			Assert::IsTrue(dft_iterator->has_next());
			Assert::IsTrue(dft_iterator->next() == 1);
			Assert::IsTrue(dft_iterator->has_next());
			Assert::IsTrue(dft_iterator->next() == 3);
			Assert::IsTrue(dft_iterator->has_next());
			Assert::IsTrue(dft_iterator->next() == 0);
			Assert::IsTrue(!dft_iterator->has_next());
			
		}

	};
}
