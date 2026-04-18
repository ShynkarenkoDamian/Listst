#include "SinglyLinkedList.h"
#include <iostream>
#include "Node.h"

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() = default;


template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    while (head != nullptr) {

        head = head->next;
    }
}


template<typename T>
bool SinglyLinkedList<T>::empty() const {
    return size == 0;
}

template<typename T>
void SinglyLinkedList<T>::push_front(T data) {
    auto newNode = std::make_shared<Node<T>>(data);
    newNode->next = head;
    head = newNode;
    size++;
}

template<typename T>
void SinglyLinkedList<T>::push_back(T data) {
    if (head == nullptr) {
        push_front(data);
        return;
    }

    auto current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = std::make_shared<Node<T>>(data);
    size++;
}

template<typename T>
void SinglyLinkedList<T>::insert(T data, int index) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0) {
        push_front(data);
    }
    else {
        auto current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        auto newNode = std::make_shared<Node<T>>(data);
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
}

template<typename T>
T& SinglyLinkedList<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index is out of range!");
    }

    auto current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->data;
}

template<typename T>
const T& SinglyLinkedList<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index is out of range!");
    }

    auto current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
void SinglyLinkedList<T>::pop_front() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    head = head->next;
    size--;
}

template<typename T>
void SinglyLinkedList<T>::pop_back() {
    if (empty()) throw std::runtime_error("List is empty");
    if (size == 1) {
        pop_front();
        return;
    }

    auto current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    current->next = nullptr;
    size--;
}

template<typename T>
void SinglyLinkedList<T>::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0) {
        pop_front();
    }
    else {
        auto current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        current->next = current->next->next;
        size--;
    }
}
template<typename T>
int SinglyLinkedList<T>::find(const T& value) const {
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
std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<U>& list) {
    auto current = list.head;
    os << "[";
    while (current != nullptr) {
        os << current->data;
        if (current->next != nullptr) {
            os << " -> ";
        }
        current = current->next;
    }
    os << "]";
    return os;
}
