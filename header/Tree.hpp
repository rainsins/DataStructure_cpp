#pragma once
#include <iostream>
#include <stdlib.h>

template <class E> class TreeNode{
    //第一儿子/下一兄弟表示法
private:
    E data;
    TreeNode<E> *FirstChild;
    TreeNode<E> *Nextsibling;

    void init(){
        data = NULL;
        FirstChild = Nextsibling = nullptr;
    }

    void clear(){
        delete FirstChild, Nextsibling;
    }

public:
    TreeNode(){
        init();
    }

    ~TreeNode(){
        clear();
    }
    //。。。不知道实现啥，先放着。
};