#pragma once
#include <iostream>
using namespace std;

#define RED true;
#define BLACK false;
using Color = bool;

template <class Key, class Value> 
class RBNode{
private:
    Key Key;
    Value Value;
    RBNode *left;
    RBNode *right;
    int N;
    Color color;

public:
    RBNode(Key ikey, Value ivalue, int inum, Color c){
        Key = ikey;
        Value = ivalue;
        N = inum;
        color = c;
        left = right = nullptr;
    }
};

template <class Key, class Value> 
class RB_tree{
private:
    RBNode* root;

    bool isRed(RBNode* h){
        if(h == nullptr) return false;
        return h->color == RED;
    }

    RBNode* rotateLeft(RBNode* h){
        RBNode *x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        x->N = h->N;
        h->N = 1 + size(h->left) + size(h->right);
        return x;
    }

    RBNode* rotateRight(RBNode* h){
        RBNode *x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = RED;
        x->N = h->N;
        h->N = 1 + size(h->left) + size(h->right);
        return x;
    }

    void flipColor(RBNode* h){
        h->color = RED;
        h->left->color = BLACK;
        h->right->color = BLACK;
    }

    RBNode* put(RBNode* h, Key key, Value value){
        
    }

    int size(RBNode* h){
        if(h == nullptr) {
            return 0;
        }else{
            return h->N;
        }; 
    }

public:
    RB_tree(){
        root = nullptr;
    }

    void put(Key key,Value value){
        root = put(root, key, value);
        root->color = BLACK;
    }
};


