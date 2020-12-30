#pragma once
#include "ADTArray.h"
class ArrayAtom :
	public ADTArrayBase
{
public:
	ArrayAtom();
	~ArrayAtom();
private:	
	// implementation of atomic functions
	void Append(T elem);
	void Resize(size_type new_size);
	T Move(size_type s, size_type d); 

public:
	// Inherited via ADTArrayBase
	virtual void Insert(size_type i, T elem) override; 
	virtual void Delete(size_type i) override;

};
