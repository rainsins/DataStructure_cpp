#pragma once
#include <iostream>
#include "myerror.hpp"
#include <stack>
#include <queue>
#include <vector>

using namespace std;

template <class E> class B_Node
{
public:
    unsigned int weight;
    B_Node<E> *left;
    B_Node<E> *right;
    bool ltag;
    bool rtag;
    E data;


    B_Node(){
        left = right = nullptr;
        ltag = rtag = false;
        weight = 0;
    }
};

template <class E> class Bitree
{
private:
    B_Node<E> *root;
    B_Node<E> *curr;

public:
    Bitree(){ 
        CreateBitree(root);
    }

    void CreateBitree(B_Node<E> *lroot){
        if(cin.peek() == '#'){
            cin.get();
            lroot = nullptr;
        }else{
            lroot =  new B_Node<E>();
            cin >> lroot->data;
            CreateBitree(lroot->left);
            CreateBitree(lroot->right);
        }
    }

    //非递归先序遍历
    vector<E> PreOrder_NotRecu(){
        stack<B_Node<E>*> temp;
        vector<E> result;

        curr = root;

        if(curr != nullptr || !temp.empty()){
            result.push_back(curr->data);
            temp.push(curr);
            curr = curr->left;
        }else{
            curr = temp.top();
            temp.pop();
            curr = curr->right;
        }

        return result;
    }


    //非递归中序遍历
    vector<E> InOrder_NotRecu(){
        stack<B_Node<E>*> temp;
        vector<E> result;

        curr = root;

        if(curr != nullptr || !temp.empty()){
            temp.push(curr);
            curr = curr->left;
        }else{
            curr = temp.top();
            result.push_back(curr->data);
            temp.pop();
            curr = curr->right;
        }

        return result;
    }

    //非递归后序遍历
    vector<E> PostOrder_NotRecu(){
        stack<B_Node<E>*> temp;
        vector<E> result;

        curr = root;
        B_Node<E> *prev = nullptr;

        if(curr != nullptr || !temp.empty()){
            temp.push(curr);
            curr = curr->left;
        }else{
            B_Node<E> *peek = temp.top();
            if(peek->right != nullptr && peek->right != prev){
                curr = peek->right;
            }else{
                result.push_back(peek->data);
                prev = peek;
                temp.pop();
            }
        }

        return result;
    }

    //层序遍历
    vector<E> LevelOrder(){
        queue<B_Node<E>*> temp;
        vector<E> result;

        curr = root;

        if(curr != nullptr){
            temp.push(curr);
        }
    
        while (!temp.empty())
        {
            curr = temp.front();
            result.push_back(curr->data);
            temp.pop();
            if(curr->left != nullptr){
                temp.push(curr->left);
            }
            if(curr->right != nullptr){
                temp.push(curr->right);
            }
        }

        return result;
    }

    B_Node<E> *InThreadTree;
    B_Node<E> *PostThreadTree;
    B_Node<E> *PreThreadTree;


    //中序线索化
    void InThread_Gen(B_Node<E>* t, B_Node<E>* pre){
        if(t != nullptr){
            InOrder_NotRecu(t->left , pre);
            if(t->left != nullptr){
                t->left = pre;
                t->ltag = true;
            }
            if(pre != nullptr && pre->right == nullptr){
                pre->right = t;
                pre->rtag = true;
            }
            pre = t;
            InOrder_NotRecu(t->right , pre);
        }
    }

    void InThread(){
        B_Node<E> *pre = nullptr;
        InThreadTree = root;
        if(root != nullptr){
            InOrder_NotRecu(InThreadTree, pre);
            pre->right = nullptr;
            pre->ltag = true;
        }

    }
    //后序线索化
    void PostThread_Gen(){
        
    }

    void PostThread(){
        
    }
    //先序线索化
    void PreThread_Gen(){

    }

    void PreThread(){
        
    }
};
