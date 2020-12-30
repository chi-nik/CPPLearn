#pragma once
#include <iostream>
class ADTArrayBase
{
protected:
	using T = int;
	using size_type = int;

	//const size_type _Size=4;
	#define ARRAY_SIZE 4

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
	
	virtual void Insert(size_type i, T elem) = 0; 
	virtual	void Delete(size_type i) = 0; 
	
	
};

