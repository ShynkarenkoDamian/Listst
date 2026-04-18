#pragma once
#include <iostream>
#include "Node.h"

template<typename T>
class DoublyLinkedList
{
private:
	std::shared_ptr<Node<T>> head = nullptr;
	std::shared_ptr<Node<T>> tail = nullptr;
	int size = 0;
public:
	DoublyLinkedList() = default;
	~DoublyLinkedList() {
		while (head != nullptr) {
			head = head->next;
		}
	}
	void push_back(T data) {
		auto newNode = std::make_shared<Node<T>>(data);
		if (empty()) {
			head = tail = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	void push_front(T data) {
		auto newNode = std::make_shared<Node<T>>(data);
		if (empty()) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		size++;
	}
	void insert(T data, int index) {
		if (index < 0 || index > size) throw std::out_of_range("Index out of range");

		if (index == 0) {
			push_front(data);
			return;
		}
		if (index == size) {
			push_back(data);
			return;
		}

		std::shared_ptr<Node<T>> current;
		if (index < size / 2) {
			current = head;
			for (int i = 0; i < index; ++i) current = current->next;
		}
		else {
			current = tail;
			for (int i = 0; i < size - index - 1; ++i) current = current->prev.lock();
		}

		auto newNode = std::make_shared<Node<T>>(data);
		auto before = current->prev.lock();

		newNode->next = current;
		newNode->prev = before;
		before->next = newNode;
		current->prev = newNode;

		size++;
	}
	void pop_back() {
		if (empty()) throw std::runtime_error("List is empty");

		if (size == 1) {
			head = tail = nullptr;
		}
		else {
			tail = tail->prev.lock();
			tail->next = nullptr;
		}
		size--;
	}
	void pop_front() {
		if (empty()) throw std::runtime_error("List is empty");

		if (size == 1) {
			head = tail = nullptr;
		}
		else {
			head = head->next;
			head->prev.reset();
		}
		size--;
	}
	void remove(int index) {
		if (index < 0 || index >= size) throw std::out_of_range("Index out of range");

		if (index == 0) {
			pop_front();
			return;
		}
		if (index == size - 1) {
			pop_back();
			return;
		}

		std::shared_ptr<Node<T>> target;
		if (index < size / 2) {
			target = head;
			for (int i = 0; i < index; ++i) target = target->next;
		}
		else {
			target = tail;
			for (int i = 0; i < size - index - 1; ++i) target = target->prev.lock();
		}

		auto before = target->prev.lock();
		auto after = target->next;

		before->next = after;
		after->prev = before;

		size--;
	}
	T& operator[](int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}

		std::shared_ptr<Node<T>> current;
		if (index < size / 2) {
			current = head;
			for (int i = 0; i < index; ++i) current = current->next;
		}
		else {
			current = tail;
			for (int i = 0; i < size - index - 1; ++i) current = current->prev.lock();
		}

		return current->data;
	}

	const T& operator[](int index) const {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}

		std::shared_ptr<Node<T>> current;
		if (index < size / 2) {
			current = head;
			for (int i = 0; i < index; ++i) current = current->next;
		}
		else {
			current = tail;
			for (int i = 0; i < size - index - 1; ++i) current = current->prev.lock();
		}

		return current->data;
	}

	int getSize() const { return size; }

	bool empty() const {
		return size == 0;
	}

	int find(const T& value) const {
		auto current = head;
		int index = 0;

		while (current != nullptr) {
			if (current->data == value) {
				return index;
			}
			current = current->next;
			index++;
		}

		return -1;
	}

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<U>& list) {

		auto current = list.head;
		os << "[ ";
		while (current != nullptr) {
			os << current->data << " ";
			current = current->next;
		}
		os << "]";
		return os;
	}
};

