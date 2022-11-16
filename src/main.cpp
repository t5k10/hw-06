#include <iostream>
#include "array_container.cpp"
#include "doubly_linked_container.cpp"
#include "linked_container.cpp"

int main() { 
    ArrayContainer values;
    for (size_t i = 0; i < 10; ++i) values.push_back(i);
    std::cout << values << '\n';
    values.size();
    values.erase(3, 5, 7);
    std::cout << values << '\n';
    values.size();
    values.insert(10, 1);
    std::cout << values << '\n'; 
    values.size();
    values.insert(20, 5);
    std::cout << values << '\n'; 
    values.size();
    values.push_back(30);
    std::cout << values << '\n';
    values.size();
    std::cout << '\n' << '\n';

    DoubleListContainer list;
    for (size_t i = 0; i < 10; ++i) list.push_back(i);
    std::cout << list << '\n';
    std::cout << list.size() << '\n';
    list.erase(3, 5, 7);
    std::cout << list << '\n';
    std::cout << list.size() << '\n';
    list.push_front(10);
    std::cout << list << '\n';
    std::cout << list.size() << '\n';
    list.insert(20, 5);
    std::cout << list << '\n';
    std::cout << list.size() << '\n';
    list.push_back(30);
    std::cout << list << '\n';
    std::cout << list.size() << '\n';
    std::cout << list[3] << '\n' << '\n';

    LinkedListContainer list2;
    for (size_t i = 0; i < 10; ++i) list2.push_back(i);
    std::cout << list2 << '\n';
    std::cout << list2.size() << '\n';
    list2.erase(3, 5, 7);
    std::cout << list2 << '\n';
    std::cout << list2.size() << '\n';
    list2.push_front(10);
    std::cout << list2 << '\n';
    std::cout << list2.size() << '\n';
    list2.insert(20, 5);
    std::cout << list2 << '\n';
    std::cout << list2.size() << '\n';
    list2.push_back(30);
    std::cout << list2 << '\n';
    std::cout << list2.size() << '\n'; 
    std::cout << list2[10] << '\n' << '\n';
    
}
