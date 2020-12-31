#pragma once
#include "ADTArray.h"
class ArrayIter :
	public ADTArrayBase
{
public:
	ArrayIter();
	~ArrayIter();


	// Inherited via ADTArrayBase

	/// Pushes next elements to the side untill the end (size)
	virtual void Insert(size_type i, T elem) override;

	virtual void Delete(size_type i) override;

	virtual size_type Search(T elem) override;

	virtual void Reverse() override;

	virtual void Shift(size_type i) override;

	virtual void Rotate(size_type i) override;

	virtual bool isSorted() override;

	virtual void Merge(T *) override;
};

