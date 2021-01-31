#pragma once
#include "AVL_BST.h"

class defender_soldier_node
{
public:
    soldier_node* sld_node;
    int degree;
    defender_soldier_node* parent;
    defender_soldier_node* child;
    defender_soldier_node* leftSibling;
    defender_soldier_node* rightSibling;
    bool mark;
    defender_soldier_node()
        : parent(nullptr)
        , child(nullptr)
        , leftSibling(nullptr)
        , rightSibling(nullptr)
        , degree(0)
        , mark(false)
    {
        sld_node = new soldier_node();
    }
    //defender_soldier_node(soldier_node* sldr)
    //{
    //    sld_node = sldr;
    //    parent = nullptr;
    //    child = nullptr;
    //    leftSibling = nullptr;
    //    rightSibling = nullptr;
    //}
    
};

class FiboHeap
{
private:
    
    defender_soldier_node* head;
    
public:
	FiboHeap();
	~FiboHeap();


};

FiboHeap::FiboHeap()
{
    this->head = new defender_soldier_node();
    this->head->parent = nullptr;
    this->head->child = nullptr;
}

FiboHeap::~FiboHeap()
{
}