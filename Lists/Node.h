#ifndef DATA_STRUCTURES_SINGLENODE_H
#define DATA_STRUCTURES_SINGLENODE_H

template<typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next = nullptr;
    std::weak_ptr<Node<T>> prev;
    Node(T val) : data(val), next(nullptr) {}
};

#endif