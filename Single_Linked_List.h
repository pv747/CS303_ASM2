#pragma once
#include <stdexcept>
#include "Node.h"

using namespace std;

template <typename T> class Single_Linked_List {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t num_items;
public:
    Single_Linked_List();
    void push_front(T val);
    void push_back(T val);
    void pop_front();
    void pop_back();
    T front();
    T back();
    bool empty();
    void insert(size_t index, const T &val);
    bool remove(size_t index);
    size_t find(const T& val);
};

// Constructor: Initializes an empty singly linked list.
template <typename T> Single_Linked_List<T>::Single_Linked_List() {
    // Initialize head and tail pointers to nullptr
    head = nullptr;
    tail = nullptr;
    // Initialize the number of items in the list to 0
    num_items = 0;
}

// Inserts a new node with the specified value at the front of the list.
// @param val - a value of T type.
template <typename T> void Single_Linked_List<T>::push_front(T val) {
    // Create a new node
    Node<T>* newN = new Node<T>();

    // Set the value of the new node to the specified value
    newN->val = val;
    // Point the new node to the current head
    newN->nxtPtr = head;
    // Update the head pointer to the new node
    head = newN;

    // If the list was initially empty, update the tail pointer
    if (tail == nullptr) {
        tail = head;
    }
    num_items += 1;
}

// Inserts a new node with the specified value at the end of the list.
// @params val - a value of T type.
template <typename T> void Single_Linked_List<T>::push_back(T val) {
    // Create a new node
    Node<T>* newN = new Node<T>();

    // Set the value of the new node to the specified value
    newN->val = val;
    // Point the new node's next pointer to nullptr
    newN->nxtPtr = nullptr;

    // If the list is empty, insert the new node at the front
    if (empty())
        push_front(val);
    else {
        // Point the current tail to the new node
        tail->nxtPtr = newN;
        // Update the tail pointer to the new node
        tail = newN;
    }
    num_items += 1;
}

// Removes the first node (head) of the list.
template <typename T> void Single_Linked_List<T>::pop_front() {
    // Check if the list is empty, and if so, throw an exception
    if (empty())
        throw std::runtime_error("Cannot pop an empty list");

    // Create a pointer to the previous head
    Node<T>* prevHead = head;
    // Update the head pointer to the next node
    head = head->nxtPtr;

    delete prevHead;
    num_items -= 1;
}

// Removes the last node (tail) of the list.
template <typename T> void Single_Linked_List<T>::pop_back() {
    // Check if the list is empty, and if so, throw an exception
    if (empty())
        throw runtime_error("Cannot pop an empty list");

    // If there is only one node in the list, remove it using pop_front
    if (tail == head)
        pop_front();
    else {
        // Create pointers to traverse the list
        Node<T>* curr = head;
        Node<T>* prevTail = tail;

        // Traverse the list to find the node before the tail
        while (curr->nxtPtr != tail) {
            curr = curr->nxtPtr;
        }

        // Update the tail pointer to the node before the current tail
        tail = curr;

        delete prevTail;
        num_items -= 1;
    }
}

//Returns the value stored in the first node (head) of the list.
//@return - head of list.
template <typename T> T Single_Linked_List<T>::front() {
    // Check if the list is empty, and if so, throw an exception
    if (empty())
        throw runtime_error("Cannot read val from empty list.");
    // Return the value stored in the head node
    return head->val;
}

// Returns the value stored in the last node (tail) of the list.
//@return - tail of list.
template <typename T> T Single_Linked_List<T>::back() {
    // Check if the list is empty, and if so, throw an exception
    if (empty())
        throw runtime_error("Cannot read val from empty list.");
    // Return the value stored in the tail node
    return tail->val;
}

// Checks if the list is empty.
//@return - boolean indicative of empty or not empty list.
template <typename T> bool Single_Linked_List<T>::empty() {
    // Check if the head pointer is nullptr, indicating an empty list
    if (head == nullptr)
        return true;
    return false;
}

// Inserts a new node with the specified value at the given index.
//@param index - index of the inserted value.
//@param val - value of type T.
template <typename T> void Single_Linked_List<T>::insert(size_t index, const T& val) {
    // Check if the index is out of bounds, and if so, throw an exception
    if (index >= num_items)
        throw runtime_error("Index out of bounds");
    else if (index == 0) {
        // If the index is 0, insert the new node at the front
        push_front(val);
        return;
    }
    else if (index == num_items - 1) {
        // If the index is the last element, insert the new node at the end
        push_back(val);
        return;
    }

    // Create a new node
    Node<T>* newN = new Node<T>();
    newN->val = val;
    // Create pointers to traverse the list
    Node<T>* prev = head;
    Node<T>* curr = head->nxtPtr;

    int i = 1;
    // Traverse the list to find the node before the specified index
    while (i < index) {
        prev = curr;
        curr = curr->nxtPtr;
        i += 1;
    }
    // Update the previous node's next pointer to the new node
    prev->nxtPtr = newN;
    // Update the new node's next pointer to the current node
    newN->nxtPtr = curr;

    // Increment the number of items in the list
    num_items += 1;
}

// Removes the node at the specified index.
//@params index - index of value to be removed.
template<typename T> bool Single_Linked_List<T>::remove(size_t index) {
    // Check if the index is out of bounds, and if so, return false
    if (index >= num_items) return false;
    else if (index == 0) {
        // If the index is 0, remove the first node using pop_front
        pop_front();
        return true;
    }
    else if (index == num_items - 1) {
        // If the index is the last element, remove the last node using pop_back
        pop_back();
        return true;
    }

    // Create pointers to traverse the list
    Node<T>* prev = head;
    Node<T>* curr = head->nxtPtr;

    int i = 1;
    // Traverse the list to find the node before the specified index
    while (i < index) {
        prev = curr;
        curr = curr->nxtPtr;
        i += 1;
    }
    // Update the previous node's next pointer to skip the current node
    prev->nxtPtr = curr->nxtPtr;
    // Delete the current node to free memory
    delete curr;
    // Decrement the number of items in the list
    num_items -= 1;
    return true;
}

// Searches for the first occurrence of the specified value in the list and returns its index.
//@params val - target value of type T.
template<typename T> size_t Single_Linked_List<T>::find(const T& val) {
    // Create a pointer to traverse the list
    Node<T>* curr = head;
    size_t i = 0;
    // Traverse the list while comparing the values
    while (curr != nullptr) {
        if (curr->val == val) return i;

        curr = curr->nxtPtr;
        i++;
    }
    // If the value is not found, return the total number of items in the list
    return num_items;
}


