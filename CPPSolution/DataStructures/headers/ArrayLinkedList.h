#pragma once
#include "ADTArray.h"
class ArrayLinkedList :
	public ADTArrayBase
{
private:
	class Node;
	Node* head= nullptr;
public:
	ArrayLinkedList();
	~ArrayLinkedList();
	virtual T* GetArray() override;// { return Array; }
	void Display()
	{
		GetArray();
		for (auto i = 0; i < length; ++i) 
		{
			std::cout << Array[i] << ","; 
		}
		std::cout << std::endl;
	}
	//virtual T* GetArray() override { return Array; } 
	virtual size_type GetSize() override { GetArray(); return size; }
	virtual size_type GetLength()  override { GetArray(); return length; }
	virtual std::vector<int> GetVector() override { GetArray(); return std::vector<int>(Array, Array + length); }

	virtual T Get(size_type i) override;
	virtual void Set(size_type i, T elem) override;
	virtual Node* Append(T elem);
	// Inherited via ADTArrayBase
	virtual T Insert(size_type i, T elem) override;
	virtual T Delete(size_type i) override;
	virtual size_type Search(T elem) override;
	virtual void Reverse() override;
	virtual void Shift(size_type i) override;
	virtual void Rotate(size_type i) override;
	virtual bool isSorted() override;
	virtual void Merge(T *) override;
	virtual void Merge(ArrayLinkedList a);
};

