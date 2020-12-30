#pragma once
#include "ADTArray.h"
class ArrayIter :
	public ADTArrayBase
{
public:
	ArrayIter();
	~ArrayIter();

	// Inherited via ADTArrayBase
	virtual void Insert(size_type i, T elem) override;
	virtual void Delete(size_type i) override;
};

