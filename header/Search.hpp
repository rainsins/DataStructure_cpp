#pragma once
using namespace std;

#define RED true;
#define BLACK false;
using Color = bool;

template <class Key, class Value> 
class RBNode{
private:
    Key Key;
    Value Value;
    RBNode<Key,Value> left;
    RBNode<Key,Value> right;
    int N;
    Color color;

public:
    RBNode(Key &ikey, Value &ivalue, int inum, Color &c){
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
    RBNode<Key,Value> root;
    RBNode<Key,Value> temp;

    bool isRed(RBNode<Key,Value> &h){
        if(h == nullptr) return false;
        return h.color == RED;
    }

    int size(RBNode<Key,Value> &h){
        if(h == nullptr) {
            return 0;
        }else{
            return h.N;
        }; 
    }

    //左转
    RBNode<Key,Value> rotateLeft(RBNode<Key,Value> &h){
        RBNode<Key,Value> x = h.right;
        h.right = x.left;
        x.left = h;
        x.color = h.color;
        h.color = RED;
        x.N = h.N;
        h.N = 1 + size(h.left) + size(h.right);
        return x;
    }

    //右转
    RBNode<Key,Value> rotateRight(RBNode<Key,Value> &h){
        RBNode<Key,Value> = h.left;
        h.left = x.right;
        x.right = h;
        x.color = h.color;
        h.color = RED;
        x.N = h.N;
        h.N = 1 + size(h.left) + size(h.right);
        return x;
    }

    //改变颜色
    void flipColor(RBNode<Key,Value> &h){
        h.color = RED;
        h.left.color = BLACK;
        h.right.color = BLACK;
    }

    //插入
    RBNode<Key,Value> put(RBNode<Key,Value> &h, Key &key, Value &value){
        if(h == nullptr){
            temp = new RBNode<Key, Value>(Key, Value, 1, RED);
            return temp;
        }
        if(key > h.key){
            h.right = put(h.right, key, value);
        }else if(key < h.key){
            h.left = put(h.left, key, value);
        }else{
            h.value = value;
        }

        if(isRed(h.right) && !isRed(h.left))
            h = rotateLeft(h);
        if(isRed(h.left) && isRed(h.left.left))
            h = rotateRight(h);
        if(isRed(h.left) && isRed(h.right))
            flipColor(h);

        h.N = 1 + size(h.left) + size(h.right);
        return h;
    }

    //删除
    


public:
    RB_tree(){
        root = temp = nullptr;
    }

    void put(Key &key,Value &value){
        root = put(root, key, value);
        root.color = BLACK;
    }

    void deleteMin(){

    }

    void deleteMax(){

    }

    void Delete(Key &key){

    }
};
