#pragma once
#include <iostream>
#include "Node.h"

template<typename T>
class SinglyLinkedList
{
private:
	std::shared_ptr<Node<T>> head = nullptr;
	int size = 0;
public: 
	SinglyLinkedList();
	~SinglyLinkedList();
	void push_back(T data);
	void push_front(T data);
	void insert(T data, int index);
	void pop_back();
	void pop_front();
	void remove(int index);
	T& operator[](int index);
	const T& operator[](int index) const;
	int getSize() const { return size; }
	bool empty() const;
	int find(const T& value) const;
	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<U>& list);
};

