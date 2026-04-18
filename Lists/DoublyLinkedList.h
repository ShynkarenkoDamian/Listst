#pragma once
#include <iostream>
#include "Node.h"

template<typename T>
class DoublyLinkedList
{
private:
	std::shared_ptr<Node<T>> head = nullptr;
	int size = 0;
public:
	DoublyLinkedList(T data);
	void push_back(T data);
	void push_front(T data);
	void insert(T data, int index);
	void pop_back();
	void pop_front();
	void remove(int index);
	T& operator[](int index);
	int getSize() const { return size; }
};

