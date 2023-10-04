#pragma once
#include <stdexcept>
#include "Node.h"

using namespace std;

template <typename T> class lList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t num_items;
public:
    lList();
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

#include "lList.h"

template <typename T> lList<T>::lList() {
    head = nullptr;
    tail = nullptr;
    num_items = 0;
}

template <typename T> void lList<T>::push_front(T val) {
    Node<T>* newN = new Node<T>();

    newN->val = val;
    newN->nxtPtr = head;
    head = newN;

    if (tail == nullptr) {
        tail = head;
    }
    num_items += 1;
}

template <typename T> void lList<T>::push_back(T val) {
    Node<T>* newN = new Node<T>();

    newN->val = val;
    newN->nxtPtr = nullptr;

    if (empty())
        push_front(val);
    else {
        tail->nxtPtr = newN;
        tail = newN;
    }
    num_items += 1;
}

template <typename T> void lList<T>::pop_front() {
    if (empty())
        throw std::runtime_error("Cannot pop an empty list");

    Node<T>* prevHead = head;
    head = head->nxtPtr;

    delete prevHead;
    num_items -= 1;
}

template <typename T> void lList<T>::pop_back() {
    if (empty())
        throw runtime_error("Cannot pop an empty list");
    if (tail == head)
        pop_front();

    Node<T>* curr = head;
    Node<T>* prevTail = tail;

    while (curr->nxtPtr != tail) {
        curr = curr->nxtPtr;
    }

    tail = curr;
    delete prevTail;
    num_items -= 1;
}

template <typename T> T lList<T>::front() {
    if (empty())
        throw runtime_error("Cannot read val from empty list.");
    return head->val;
}

template <typename T> T lList<T>::back() {
    if (empty())
        throw runtime_error("Cannot read val from empty list.");
    return tail->val;
}

template <typename T> bool lList<T>::empty() {
    if (head == nullptr)
        return true;
    return false;
}

template <typename T> void lList<T>::insert(size_t index, const T& val) {
    if (index >= num_items)
        throw runtime_error("Index out of bounds");
    else if (index == 0) {
        push_front(val);
        return;
    }
    else if (index == num_items - 1) {
        push_back(val);
        return;
    }

    Node<T>* newN = new Node<T>();
    newN->val = val;
    Node<T>* prev = head;
    Node<T>* curr = head->nxtPtr;

    int i = 1;
    while (i < index) {
        prev = curr;
        curr = curr->nxtPtr;
        i += 1;
    }
    prev->nxtPtr = newN;
    newN->nxtPtr = curr;

    num_items += 1;
}

template<typename T>
bool lList<T>::remove(size_t index) {
    if (index >= num_items) return false;
    else if (index == 0) {
        pop_front();
        return true;
    }
    else if (index == num_items - 1) {
        pop_back();
        return true;
    }

    Node<T>* prev = head;
    Node<T>* curr = head->nxtPtr;

    int i = 1;
    while (i < index) {
        prev = curr;
        curr = curr->nxtPtr;
        i += 1;
    }
    prev->nxtPtr = curr->nxtPtr;
    delete curr;
    num_items -= 1;
    return true;
}

template<typename T>
size_t lList<T>::find(const T& val) {
    Node<T>* curr = head;
    size_t i = 0;
    while (curr != nullptr) {
        if (curr->val == val) return i;

        curr = curr->nxtPtr;
        i++;
    }
    return num_items;
}


