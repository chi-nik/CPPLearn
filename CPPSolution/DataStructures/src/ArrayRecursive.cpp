#include "../headers/ArrayRecursive.h"

ArrayRecursive::ArrayRecursive()
{
}

ArrayRecursive::~ArrayRecursive()
{
}

ArrayRecursive::T ArrayRecursive::Insert(size_type i, T elem)
{
	// stop condition
	if (i >= length )
	{
		Array[i] = elem;
		if(length < size) length++;

	}
	else
	{
		// auto old_value= Array[i];
		// Array[i] = elem;
		Insert(i + 1, Array[i]);
		Array[i] = elem;
	}
	return elem;
}

ArrayRecursive::T ArrayRecursive::Delete(size_type i)
{
	return T();
}

ArrayRecursive::size_type ArrayRecursive::Search(T elem)
{
	return size_type();
}

void ArrayRecursive::Reverse()
{
}

void ArrayRecursive::Shift(size_type i)
{
}

void ArrayRecursive::Rotate(size_type i)
{
}

bool ArrayRecursive::isSorted()
{
	return false;
}

void ArrayRecursive::Merge(T *)
{
}
