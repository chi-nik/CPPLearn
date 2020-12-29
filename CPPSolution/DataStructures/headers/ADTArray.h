#pragma once
#include <iostream>
class ADTArray
{
private:
	using T = int;
	using size_type = int;

	//const size_type _Size=4;
#define ARRAY_SIZE 4

	size_type length;
	size_type size;
	T* Array;

		
public:
	ADTArray()
	{
		Array = new T[ARRAY_SIZE];
		size = ARRAY_SIZE;
		length = ARRAY_SIZE;

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
	
	void Add(size_type n);
	
	// insert(Index i, v
	
};

