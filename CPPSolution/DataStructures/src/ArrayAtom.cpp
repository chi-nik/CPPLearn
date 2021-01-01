#include "../headers/ArrayAtom.h"

ArrayAtom::ArrayAtom()
{
}

ArrayAtom::~ArrayAtom()
{
}

void ArrayAtom::Append(T elem)
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

void ArrayAtom::Resize(size_type new_size) {
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

ArrayAtom::T ArrayAtom::Move(size_type s, size_type d)
{
	auto former_dest = Array[d];
	Array[d] = Array[s];
	return  former_dest;
}

ArrayAtom::T ArrayAtom::Insert(size_type i, T elem)
{
	if (i < length) {
		Insert(i + 1, Array[i]);
		Array[i] = elem;
	}
	else
	{
		Append(elem);
	}
	return -1; //Doesn't matter
}

ArrayAtom::T ArrayAtom::Delete(size_type i)
{

	if (i < length - 1)
	{
		Move(i + 1, i);
		Delete(i + 1);
	}
	else {
		length--;
	}
	return -1;// Doesn't matter




}

ArrayAtom::size_type ArrayAtom::Search(T elem)
{
	return size_type();
}

void ArrayAtom::Reverse()
{
}

void ArrayAtom::Shift(size_type i)
{
}

void ArrayAtom::Rotate(size_type i)
{
}

bool ArrayAtom::isSorted()
{
	return false;
}

void ArrayAtom::Merge(T *)
{
}
