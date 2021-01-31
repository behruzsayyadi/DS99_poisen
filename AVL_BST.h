#pragma once
#include<iostream>


int max(int a, int b)
{
    return a > b ? a : b;
}
using namespace std;

struct soldier_node
{
    int data;
    soldier_node* left;
    soldier_node* right;
    int height;
};

class BST
{
    friend class Castle;
    
    soldier_node* root;

    void makeEmpty(soldier_node* t)
    {
        if (t == nullptr)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    soldier_node* insert(int x, soldier_node* t)
    {
        if (t == nullptr)
        {
            t = new soldier_node;
            t->data = x;
            t->height = 0;
            t->left = t->right = nullptr;
        }
        else if (x < t->data)
        {
            t->left = insert(x, t->left);
            if (height(t->left) - height(t->right) == 2)
            {
                if (x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if (x >= t->data)
        {
            t->right = insert(x, t->right);
            if (height(t->right) - height(t->left) == 2)
            {
                if (x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }
        else if (x == t->data)
            return t;

        t->height = max(height(t->left), height(t->right)) + 1;
        return t;
    }

    soldier_node* singleRightRotate(soldier_node*& t)
    {
        if (t->left != nullptr) {
            soldier_node* u = t->left;
            t->left = u->right;
            u->right = t;
            t->height = max(height(t->left), height(t->right)) + 1;
            u->height = max(height(u->left), t->height) + 1;
            return u;
        }
        return t;
    }
    soldier_node* singleLeftRotate(soldier_node*& t)
    {
        if (t->right != nullptr) {
            soldier_node* u = t->right;
            t->right = u->left;
            u->left = t;
            t->height = max(height(t->left), height(t->right)) + 1;
            u->height = max(height(t->right), t->height) + 1;
            return u;
        }
        return t;
    }

    soldier_node* doubleLeftRotate(soldier_node*& t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    soldier_node* doubleRightRotate(soldier_node*& t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    soldier_node* findMin(soldier_node* t)
    {
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    soldier_node* findMax(soldier_node* t)
    {
        if (t == nullptr)
            return nullptr;
        else if (t->right == nullptr)
            return t;
        else
            return findMax(t->right);
    }

    soldier_node* remove(int x, soldier_node* t)
    {
        soldier_node* temp;

        if (t == nullptr)
            return nullptr;

        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if (t->left == nullptr)
                t = t->right;
            else if (t->right == nullptr)
                t = t->left;
            delete temp;
        }
        if (t == nullptr)
            return t;

        t->height = max(height(t->left), height(t->right)) + 1;
        if (height(t->left) - height(t->right) == 2)
        {
            if (height(t->left->left) - height(t->left->right) == 1)
                return singleRightRotate(t);
            else
                return doubleRightRotate(t);
        }
        else if (height(t->right) - height(t->left) == 2)
        {
            if (height(t->right->right) - height(t->right->left) == 1) {
                return singleLeftRotate(t);
            }
            else
                return doubleLeftRotate(t);
        }
        return t;
    }

    int height(soldier_node* t)
    {
        return (t == nullptr ? -1 : t->height);
    }

    int getBalance(soldier_node* t)
    {
        if (t == nullptr)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    void inorder(soldier_node* t)
    {
        if (t == nullptr)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

public:
    BST()
    {
        root = nullptr;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }

    int root_height()
    {
        return root->height;
    }
};