#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main() {
    std::cout << "=== Singly Linked list ===\n";
    try {
        SinglyLinkedList<int> sList;
        sList.push_back(10);
        sList.push_back(20);
        sList.push_front(5);
        sList.insert(15, 2);

        std::cout << "List: " << sList << std::endl;
        std::cout << "Size: " << sList.getSize() << std::endl;
        std::cout << "Element with index 2: " << sList[2] << std::endl;
        std::cout << "Search 20: index " << sList.find(20) << std::endl;

        sList.pop_front();
        sList.remove(1);
        std::cout << "After remove: " << sList << "\n\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error SinglyList: " << e.what() << std::endl;
    }

    std::cout << "=== Dualy linked List ===\n";
    try {
        DoublyLinkedList<std::string> dList;
        dList.push_back("C++");
        dList.push_back("Java");
        dList.push_front("Python");

        std::cout << "List: " << dList << std::endl;
        std::cout << "Last element: " << dList[dList.getSize() - 1] << std::endl;

        std::cout << "Try to get unexisting index..." << std::endl;
        std::cout << dList[10];
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Catched exeption: " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Catched runtime exeption: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Undefined error!" << std::endl;
    }
    return 0;
}
