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
    bool fighter;
};

class FiboHeap
{
public:
    defender_soldier_node* min_node;
    int num_of_nodes;
    FiboHeap();
    ~FiboHeap();


    void Insert(int key,bool fight);
    defender_soldier_node* mergeToCircute(defender_soldier_node* our_node, defender_soldier_node* circute_node);
    defender_soldier_node* childCircute(defender_soldier_node* t);

    defender_soldier_node* popMin();
    void delete_no_fight();
    void remake();
    void makeChild(defender_soldier_node* child, defender_soldier_node* parent);

    defender_soldier_node* removeNode(defender_soldier_node* node);
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

inline void FiboHeap::Insert(int key,bool fight)
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
        min_node->sld_power = key;
        min_node->fighter = fight;
        return;
    }
    defender_soldier_node* t = new defender_soldier_node;
    t->child = nullptr;
    t->degree = 0;
    t->mark = false;
    t->parent = nullptr;
    t->sld_power = key;
    t->fighter = fight;
    t->leftSibling = t;
    t->rightSibling = t;
    this->mergeToCircute(t, min_node);
    this->num_of_nodes++;

}

inline defender_soldier_node* FiboHeap::mergeToCircute(defender_soldier_node* our_node, defender_soldier_node* circute_node)
{
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
    //    circute_node->min_node->leftSibling = t;
    //}
    if (our_node == nullptr || circute_node == nullptr)
        return nullptr;
    defender_soldier_node* a;
    a = our_node->leftSibling;
    circute_node->leftSibling->rightSibling = our_node;
    our_node->leftSibling = circute_node->leftSibling;
    a->rightSibling = circute_node;
    circute_node->leftSibling = a;
    return circute_node;
}

inline defender_soldier_node* FiboHeap::childCircute(defender_soldier_node* t)
{
    if (t == nullptr)
        return nullptr;
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

inline defender_soldier_node* FiboHeap::popMin()
{
    //defender_soldier_node* popping_minimum = min_node;
    /*
    log2(200) / log2(1.618) is the maximum array lenght we need ~ 11
    */
    //defender_soldier_node** check_arr = new defender_soldier_node*[12];


    
    return NULL;
}

inline void FiboHeap::delete_no_fight()
{
    bool flag = false;
    
    defender_soldier_node* min = this->min_node;
    while (true)
    {
        if (min->fighter)
        {
            min = min->rightSibling;
        }
        else 
        {
            break;
        }

    }
    if (min == min->leftSibling)
        flag = true;
    if (min != nullptr)
    {
        childCircute(min->child);
        mergeToCircute(min->child, min);
        removeNode(min);
        if (flag)
            return;
        else
        {
            this->min_node = min->leftSibling;
            this->remake();
        }
        this->num_of_nodes--;
    }
    return;
}

inline void FiboHeap::remake()
{
    defender_soldier_node** check_arr = new defender_soldier_node * [12];
    for (int i = 0; i < 12; i++)
    {
        check_arr[i] = nullptr;
    }

    defender_soldier_node* iter = this->min_node;
    
    bool break_flag = false;
    /*while (true)
    {
        
        iter = iter->rightSibling;
        if (check_arr[iter->degree] == nullptr)
        {
            check_arr[iter->degree] = iter;

        }
        else
        {
            if (iter->sld_power > check_arr[iter->degree]->sld_power)
                makeChild(iter, check_arr[iter->degree]);
            else
                makeChild(check_arr[iter->degree], iter);
            check_arr[iter->degree] = nullptr;
            iter = min_node;
        }
        
    }*/
    while (true)
    {
        int d = iter->degree;
        while (check_arr[d] != nullptr)
        {
            defender_soldier_node* y = check_arr[d];
            if (y == iter)
            {
                break_flag = true;  
                break;			   
            }
            if (iter->sld_power > y->sld_power)  
                                
            {
                defender_soldier_node* temp = iter;
                iter = y;
                y = temp;
            }
            makeChild(y, iter); 
            check_arr[d++] = nullptr;   
        }
        if (break_flag)
            break;
        check_arr[iter->degree] = iter;
        iter = iter->rightSibling;
    }
    this->min_node = iter; 
    defender_soldier_node* iter_ = iter;
    do {
        if (iter_->sld_power < min_node->sld_power)
            min_node = iter_;
        iter_ = iter_->rightSibling;
    } while (iter_ != iter);
    delete[]check_arr;
}

inline void FiboHeap::makeChild(defender_soldier_node* child, defender_soldier_node* parent)
{
    removeNode(child);
    child->leftSibling = child->rightSibling = child;
    child->parent = parent;
    parent->child = mergeToCircute(child, parent->child);
    parent->degree++;
    child->mark = false;// hmmm.....
}


inline defender_soldier_node* FiboHeap::removeNode(defender_soldier_node* node)
{
    defender_soldier_node* node_right, * node_left;
    node_right = node->rightSibling;
    node_left = node->leftSibling;
    node_left = node_right;
    node_right = node_left;
    return node;
}

