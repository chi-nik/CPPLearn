#include "../headers/ArrayIter.h" 

ArrayIter::ArrayIter()
{
}
ArrayIter::~ArrayIter()
{
}

ArrayIter::T ArrayIter::Insert(size_type i, T elem)
{
	// Corner cases
	// i L S
	// 1. l == S (done)
	// 2. i > l
	int j = length < size ? length++ : length - 1;
	for (; j > i; j--) Array[j] = Array[j - 1]; 
	Array[i] = elem;
	return -1; //doesn't matter

}

ArrayIter::T ArrayIter::Delete(size_type i)
{
	// Corner cases
	// i L S
	// 2. i > l
	length--;
	for (int j = i ; j < length; j++) Array[j] = Array[j+1]; 
	return -1; //doesn't matter

}

ArrayIter::size_type ArrayIter::Search(T elem)
{
	return size_type();
}

void ArrayIter::Reverse()
{
}

void ArrayIter::Shift(size_type i)
{
}

void ArrayIter::Rotate(size_type i)
{
}

bool ArrayIter::isSorted()
{
	return false;
}

void ArrayIter::Merge(T *)
{
}

