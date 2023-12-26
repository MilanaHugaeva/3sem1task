#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1.1/Dequeue.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DequeueTests
{
	TEST_CLASS(DequeueTests)
	{                       
	public:
		
		TEST_METHOD(DequeueInt_ValidData_Success)
		{
			const size_t size = 5;
			auto dequeue = new Dequeue<int>(size);

			Assert::IsNotNull(dequeue);	
		}

		TEST_METHOD(DequeueString_ValidData_Success)
		{
			const size_t size = 5;
			auto dequeue = new Dequeue<std::string>(size);

			Assert::IsNotNull(dequeue);
		}

		TEST_METHOD(TakeFront_DequeueString_ValidData) 
		{
			const size_t size = 5;
			auto dequeue = new Dequeue<std::string>(size);
			dequeue->offerFront("0");
			Assert::IsTrue(dequeue->getFront() == "0");
		}

		TEST_METHOD(TakeFront_DequeueInt_ValidData)
		{
			const size_t size = 5;
			auto dequeue = new Dequeue<int>(size);
			dequeue->offerFront(0);
			Assert::IsTrue(dequeue->getFront() == 0);
		}

		TEST_METHOD(TakeBack_DequeueString_ValidData)
		{
			const size_t size = 5;
			auto dequeue = new Dequeue<std::string>(size);
			dequeue->offerBack("0");
			Assert::IsTrue(dequeue->getBack() == "0");
		}

		TEST_METHOD(TakeBack_DequeueInt_ValidData)
		{
			const size_t size = 5;
			auto dequeue = new Dequeue<int>(size);
			dequeue->offerBack(0);
			Assert::IsTrue(dequeue->getBack() == 0);
		}

		TEST_METHOD(ComparionOperator_ValidData_Success)
		{
			auto dequeueone = new Dequeue<int>(1);
			dequeueone->offerFront(1);

			auto dequeuetwo = new Dequeue<int>(1);
			dequeuetwo->offerFront(1);

			Assert::IsFalse(dequeueone == dequeuetwo);
		}

		TEST_METHOD(IsCollectionClear_ValidData_Success)
		{
			auto dequeue = new Dequeue<int>(1);
			Assert::IsTrue(dequeue->isEmpty());
		}

		TEST_METHOD(IsCollectionFull_ValidData_Success)
		{
			auto dequeue = new Dequeue<int>(1);
			dequeue->offerFront(1);

			Assert::IsTrue(dequeue->isFull());
		}
	};
}
