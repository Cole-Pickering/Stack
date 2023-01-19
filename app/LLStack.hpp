#ifndef __ICS46_LL_STACK_HPP
#define __ICS46_LL_STACK_HPP

#include <iostream>
#include "runtimeexcept.hpp"

class StackEmptyException : public RuntimeException 
{
public:
	StackEmptyException(const std::string & err) : RuntimeException(err) {}
};

// This is the LLStack class you will be implementing for this project.
// Remember to see the write-up for more details!
template<typename Object>
class LLStack
{
private:
	// fill in private member data here

	// Linked list class for nodes
	struct LL
	{
		LL* next;
		Object val;
	};

	//Head node in stack
	LL* head;


public:

	// constructor
	LLStack();

	// copy constructor (remember, deep copy!)
	LLStack(const LLStack & st);

	// assignment operator (remember, deep copy!)
	LLStack & operator=(const LLStack & st);

	// destructor
	~LLStack();

	size_t size() const noexcept;
	bool isEmpty() const noexcept;

	// We have two top() functions.  The first gets called if your LLStack is not
	// a const, while the latter gets called on a const LLStack
	// (the latter might occur via const reference parameter, for instance).
	// Be sure to test both!  It is important when testing to ensure that
	// EVERY funtion gets called and tested!
	Object & top();
	const Object & top() const;

	void push(const Object & elem) noexcept;
	void pop();
};

template <typename Object>
LLStack<Object>::LLStack()
{
	this->head = NULL;
}

template <typename Object>
LLStack<Object>::LLStack(const LLStack & st)
{
	// TODO: Fill in your copy constructor implementation here.

	this->head = NULL;
	LL* temp = st.head;
	while(temp){
		this->push(temp->val);
		temp = temp->next;
	}

}

template <typename Object>
LLStack<Object> & LLStack<Object>::operator=(const LLStack & st)
{
	// TODO: Fill in your assignment operator implementation here.
	this->~LLStack();
	this->head = NULL;
	LL* temp = st.head;
	while(temp){
		this->push(temp->val);
		temp = temp->next;
	}
	return *this;

}

template <typename Object>
LLStack<Object>::~LLStack()
{
	// TODO: Fill in your destructor implementation here.
	
	if (head){
	LL* temp = head->next;
	delete head;
	while (temp){
		head = temp;
		temp = temp->next;
		delete head;
	}
	}

}

template <typename Object>
size_t LLStack<Object>::size() const noexcept
{
	// TODO: Fill in your size() implementation here.
	int s = 0;
	LL* temp = head;
	while(temp){
		s+=1;
		temp = temp->next;
	}
	return s; // Stub so this function compiles without an implementation.
}

template <typename Object>
bool LLStack<Object>::isEmpty() const noexcept
{
	// TODO: Fill in your isEmpty() implementation here.
	if (head){
		return false;
	}
	return true;
}

template <typename Object>
Object& LLStack<Object>::top()
{
	// TODO: Fill in your top() implementation here.
	// The following is a stub just to get the template project to compile.
	// You should delete it for your implementation.

	if(!head){
		throw StackEmptyException("Stack Empty");
	}
	return head->val;
	
}

template <typename Object>
const Object& LLStack<Object>::top() const
{
	// TODO: Fill in your const top() implementation here.
	// The following is a stub just to get the template project to compile.
	// You should delete it for your implementation.
	if(!head){
		throw StackEmptyException("Stack Empty");
	}
	return head->val;
}

template <typename Object>
void LLStack<Object>::push(const Object& elem) noexcept
{
	// TODO: Fill in your push() implementation here.
	LL* temp = head;
	head = new LL;
	head->next = temp;
	head->val = elem;
}

template <typename Object>
void LLStack<Object>::pop()
{
	// TODO: Fill in your pop() implementation here.
	//                                                               TEST IS EMPTY FIRST
	
	LL* temp = head;
	head = head->next;
	delete temp;
	
}









#endif 
