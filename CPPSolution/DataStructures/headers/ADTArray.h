#pragma once
#include <iostream>
class ADTArray
{
private:
	using T = int;
	using size_type = int;

	//const size_type _Size=4;
#define ARRAY_SIZE 4

	size_type length; // what is the last element of the array
	size_type size; // how large is the array in memory
	T* Array;

		
public:
	ADTArray()
	{
		Array = new T[ARRAY_SIZE];
		size = ARRAY_SIZE;
		length = 0;
		Append(1);
		Append(2);
		Append(3);

	}
	//~ADTArray();
	void Append(T elem)
	{
		if (length < size)
		{
			Array[length++] = elem; 
		}
		else
		{
			Resize(size + 1);
			Append(elem);

		}
	}
	void Resize(size_type new_size) 
	{
		// allocate, then copy, delete
		if (new_size > size)
		{ 
			std::cout << "Growing the array to" << new_size << std::endl;

			auto ta = new T[new_size];
			for (auto i = 0; i < length; ++i)
			{
				ta[i] = Array[i]; 
			}
			delete[] Array;
			Array = ta;
			size = new_size;
			ta = nullptr; 
		}
		// TODO: Implement when new_size < size


	}

	void Display()
	{
		for (auto i = 0; i < length; ++i) 
		{
			std::cout << Array[i] << ","; 
		}
		std::cout << std::endl;
	}
	
	void Insert(size_type i, T elem) 
	{
		if(i<length){
		Insert(i + 1, Array[i]);
		Array[i] = elem;
		}
		else
		{
			Append(elem);
		} 
	}

	T Move(size_type s, size_type d) 
	{ 
		auto former_dest = Array[d];
		Array[d] = Array[s];
		return  former_dest;
	}

	void Delete(size_type i)
	{
		if (i < length-1)
		{
			Move(i + 1, i);
			Delete(i + 1);
		}
		else {
			length--;
		}


	}
		

	
	// insert(Index i, v
	
};

