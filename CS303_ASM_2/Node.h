#pragma once
template < typename T> class Node
{
public:
    T val;
    Node* nxtPtr;
    Node() {
        val = NULL;
        nxtPtr = nullptr;
    }
};

