#include "../headers/ArrayLinkedList.h"
#include <iostream>


class ArrayLinkedList::Node {
public:
	T val;
	Node* next;
	Node() { 
		next = nullptr;
		val = T(); 
	}

};
ArrayLinkedList::ArrayLinkedList()
{
}

ArrayLinkedList::T ArrayLinkedList::Get(size_type i)
{ 
	Node* it = head;
	T get_value;
	size_type it_i = 0;
	while (it ) { 
		if (it_i++ == i) return it->val; 
		it = it->next;
	} 


	return -1; 
}
ArrayLinkedList::Node* ArrayLinkedList::Append(T elem) {

	Node* it = head;
	Node* new_node = new Node;
	new_node->val = elem;
	


	// find last node
	while (it && it->next) { //&& it so it would work for empty array
		it = it->next; 
	}

	if (!head) {
		head = new_node;
	}
	else
	{
		it->next = new_node;
	};

	return new_node;


}
void ArrayLinkedList::Set(size_type i, T elem)
{
	Node* it = head;
	T get_value;
	size_type it_i = 0;

	while (it_i <= i) { 
		if (!it) it=Append(T());
		if(it_i != i) it = it->next; //don't move to the next node
		it_i++;
	} 
	it->val = elem;

}
// Virtual Functions
ArrayLinkedList::~ArrayLinkedList()
{
}

ArrayLinkedList::T * ArrayLinkedList::GetArray()
{ 
	//std::cout << " IN GET ARRAY OF ARRAYLINKEDLIST";
	//conver to an array 
	Node* it = head;
	T get_value;
	size_type it_i = 0;
	while (it) { 
		it_i++;
		it = it->next;
	} 
	T* new_array = new T[it_i];
	it_i = 0;
	it = head; 
	while (it) { 
		new_array[it_i++] = it->val;
		it = it->next;
	};

	length = it_i;
	size = it_i;
		 
	delete[] Array;
	Array = new_array; 
	return Array;

}

 ArrayLinkedList::T ArrayLinkedList::Insert(size_type i, T elem)
{
	 return T();
}

 ArrayLinkedList::T ArrayLinkedList::Delete(size_type i)
{
	return T();
}

 ArrayLinkedList::size_type ArrayLinkedList::Search(T elem)
{
	return size_type();
}

void ArrayLinkedList::Reverse()
{
}

void ArrayLinkedList::Shift(size_type i)
{
}

void ArrayLinkedList::Rotate(size_type i)
{
}

bool ArrayLinkedList::isSorted()
{
	return false;
}

void ArrayLinkedList::Merge(T *)
{
}

void ArrayLinkedList::Merge(ArrayLinkedList m)
{
}
