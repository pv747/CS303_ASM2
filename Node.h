#pragma once
template < typename T> class Node
{
public:
    T val;
    Node* nxtPtr;
    Node() {
        val = -99999;
        nxtPtr = nullptr;
    }
};

