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
	// binary search 
	if (isAlwaySorted) {
		size_type l=0 , m=length/2, h=length-1;
		while (l <= h) {
			if (elem == Array[m])
			{ 
				return m;
			}
			else
			{ 
				if (elem < Array[m]) 
				{ 
					h = m - 1; 
				}
				else
				{
					l = m + 1;
				}
			}
			m =  ((h + l) / 2); 
		} 
	}
	// Linear search
	else 
	{
		for (int i = 0; i < length; ++i) {
			if (Array[i] == elem) return i;
		} 
	}
	return -1;
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

