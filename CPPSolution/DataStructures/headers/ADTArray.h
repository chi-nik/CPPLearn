#pragma once
#include <iostream>
#include <vector>
class ADTArrayBase
{
protected:
	using T = int;
	using size_type = int;

	//const size_type _Size=4;
	#define ARRAY_SIZE 10 

	size_type length; // what is the last element of the array
	size_type size; // how large is the array in memory
	T* Array;

		
public:
	ADTArrayBase()
	{
		Array = new T[ARRAY_SIZE];
		size = ARRAY_SIZE;
		length = 0;

	}
	//~ADTArray();
	void Display()
	{
		for (auto i = 0; i < length; ++i) 
		{
			std::cout << Array[i] << ","; 
		}
		std::cout << std::endl;
	}
	virtual T* GetArray() { return Array; } 
	virtual size_type GetSize() { return size; } 
	virtual size_type GetLength() { return length; }
	virtual std::vector<int> GetVector() { return std::vector<int>(Array, Array+length); }

	virtual T Get(size_type i) { return Array[i]; }
	virtual void Set(size_type i, T elem) 
	{ 
		if (i < length)
		{
			Array[i] = elem;
		}
		else if (i < size)
		{
			// Set all values to default (0) 
			for (int j = length; j < i; j++)
				Array[j] = 0;
			Array[i] = elem;
			length = i + 1;



		}
	}
	// Abstract functions
	virtual void Insert(size_type i, T elem) = 0; 
	virtual	void Delete(size_type i) = 0; 
	virtual	size_type Search(T elem) = 0; 
	
	virtual	void Reverse() = 0; 
	virtual	void Shift(size_type i) = 0; 
	virtual	void Rotate(size_type i) = 0; 
	virtual	bool isSorted() = 0; 
	virtual void Merge(T*) = 0;
	
};

