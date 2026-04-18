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
	DoublyLinkedList();
	void push_back(T data);
	void push_front(T data);
	void insert(T data, int index);
	void pop_back();
	void pop_front();
	void remove(int index);
	T& operator[](int index);
	int getSize() const { return size; }
	bool empty() const;
	int find(const T& value) const;
	friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& list);
};

