#pragma once
#include "AVL_BST.h"

struct defender_soldier_node
{
    int sld_power;
    int degree;
    defender_soldier_node* parent;
    defender_soldier_node* child;
    defender_soldier_node* leftSibling;
    defender_soldier_node* rightSibling;
    bool mark;
};

class FiboHeap
{
public:
    defender_soldier_node* min_node;
    int num_of_nodes;
    FiboHeap();
    ~FiboHeap();
    void Insert(int key);
    void mergeToRoot(defender_soldier_node* t);

    defender_soldier_node* childCircute(defender_soldier_node* t);
};

FiboHeap::FiboHeap()
{

    //min_node->child = nullptr;
    //min_node->mark = false;
    //min_node->leftSibling = min_node;
    //min_node->rightSibling = min_node;
    //min_node->parent = nullptr;
    //min_node->degree = 0;
    //min_node->sld_power = 0;

    //min_node = nullptr;
    //num_of_nodes = 0;
    min_node = nullptr;
    num_of_nodes = 0;
}

FiboHeap::~FiboHeap()
{
}

inline void FiboHeap::Insert(int key)
{
    defender_soldier_node* t = new defender_soldier_node;
    t->child = nullptr;
    t->degree = 0;
    t->mark = false;
    t->parent = nullptr;
    t->sld_power = key;
    t->leftSibling = t;
    t->rightSibling = t;
    this->mergeToRoot(t);
}

inline void FiboHeap::mergeToRoot(defender_soldier_node* t)
{
    if (this->min_node == nullptr)
    {
        min_node = new defender_soldier_node;
        min_node->child = nullptr;
        min_node->mark = false;
        min_node->leftSibling = min_node;
        min_node->rightSibling = min_node;
        min_node->parent = nullptr;
        min_node->degree = 0;
        min_node->sld_power = 0;
    }
    //if (t->leftSibling == t)
    //{
    //    t->leftSibling = this->min_node->leftSibling;
    //    this->min_node->leftSibling->rightSibling = t;
    //    this->min_node->leftSibling = t;
    //    t->rightSibling = min_node;
    //}
    //else 
    //{
    //    t->leftSibling->rightSibling = this->min_node;
    //    this->min_node->leftSibling->rightSibling = t;
    //    this->min_node->leftSibling = t;
    //}
    defender_soldier_node* a;
    a = t->leftSibling;
    this->min_node->leftSibling->rightSibling = t;
    t->leftSibling = this->min_node->leftSibling;
    a->rightSibling = min_node;
    this->min_node->leftSibling = a;
    this->num_of_nodes++;
}
inline defender_soldier_node* FiboHeap::childCircute(defender_soldier_node* t)
{
    defender_soldier_node* circute = t;

    circute->parent = nullptr;
    circute = circute->leftSibling;
    while (circute != t)
    {
        circute->parent = nullptr;
        circute = circute->leftSibling;
    }
    return circute;
}