// Lab17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class MyIntVector
{
public:
	int length;
	int capacity;
	int* dataPointer;
	MyIntVector()
	{
		length = 0;
		capacity = 1;
		dataPointer = new int[1];
	}
	MyIntVector(const MyIntVector& rhs)
	{
		length = rhs.length;
		capacity = rhs.capacity;
		dataPointer = new int[rhs.capacity];
		for (int i = 0; i < rhs.length; ++i)
		{
			dataPointer[i] = rhs.dataPointer[i];
		}

	}
	MyIntVector(int inputArray[], int inLength)
	{
		length = inLength;
		capacity = inLength;
		dataPointer = new int[inLength];
		for (int i = 0; i < inLength; ++i)
		{
			dataPointer[i] = inputArray[i];
		}

	}
	MyIntVector& operator= (const MyIntVector& rhs)
	{
		MyIntVector temp;
		temp.length = rhs.length;
		temp.capacity = rhs.capacity;
		temp.dataPointer = new int[rhs.capacity];
		for (int i = 0; i < rhs.length; ++i)
		{
			temp.dataPointer[i] = rhs.dataPointer[i];
		}
		return temp;
	}
	void UpCapacity(int NewCapacity)
	{
		if (NewCapacity > capacity)
		{
			int* new_dataPointer = new int[NewCapacity];
			for (int j = 0; j < length; ++j)
			{
				new_dataPointer[j] = dataPointer[j];
			}
			delete[] dataPointer;
			dataPointer = new_dataPointer;
			capacity = NewCapacity;
			length = NewCapacity;
		}
		length = NewCapacity;
	}
	int& operator[](int index)
	{
		return dataPointer[index];
	}
	bool IsEmpty() const
	{
		return !length;
	}
	int Length() const
	{
		return length;
	}
	int Capacity() const
	{
		return capacity;
	}
	void PushBack(int a)
	{
		UpCapacity(length + 1);
		dataPointer[length - 1] = a;
	}
	void InputMyIntVector(MyIntVector& inVector, int N)
	{
		int* temp_pointer = new int[N];
		for (int i = 0; i < N; ++i)
		{
			cin >> temp_pointer[i];
		}
		inVector.capacity = N;
		inVector.length = N;
		inVector.dataPointer = temp_pointer;
	}
	void OutputMyIntVector(const MyIntVector& outVector)
	{
		for (int i = 0; i < outVector.length; ++i)
		{
			cout << outVector.dataPointer[i] << ' ';
		}
	}
	~MyIntVector()
	{
		delete[] dataPointer;
	}
};

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	MyIntVector temp(a, 10);
	temp.OutputMyIntVector(temp);


}



