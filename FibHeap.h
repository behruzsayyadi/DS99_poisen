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
    char C;
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
}

FiboHeap::~FiboHeap()
{
}