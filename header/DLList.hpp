#pragma once
#include <iostream>
#include "myerror.hpp"
#include "Node.hpp"

//双链表
template <class E> class DLList {
private:
	DNode<E>* head;
	DNode<E>* tail;
	DNode<E>* curr;

	int len = 0;

	//初始化双链表
	void init() {
		head = tail = curr = new DNode<E>();

		len = 0;
	}

	//清除节点
	void clear_all() {
		while (head != nullptr)
		{
			curr = head;
			head = head->next;
			delete curr;
		}
	}

	//得到第l个节点的指针
	DNode<E>* GetElem(int l) {
		curr = head;
		while (curr != nullptr && l > 0)
		{
			curr = curr->next;
			l--;
		}
		return curr;
	}

public:
	//构造函数
	DLList() {
		init();
	}
	//析构函数
	~DLList() {
		clear_all();
	}

	//返回长度
	int Length() const {
		return len;
	}

	//在第l个位置插入一个新节点，节点的数据为e
	void DlistInsert(int l, E e) {
		if (l + 1 > len) Log::Error("List length exceeded!");
		if (l < 0) Log::Error("invalid subscript!");

		DNode<E>* elem = new DNode<E>(e);
		curr = GetElem(l);

		elem->next = curr;
		elem->prior = curr->prior;
		curr->prior->next = elem;
		curr->prior = elem;

		if (l == len + 1) {
			tail = elem;
		}
		len++;
	}

	//输出链表
	void PrintList() {
		curr = head;
		while (curr != nullptr)
		{
			std::cout << curr->element << "->";
			curr = curr->next;
		}
	}

	//删除第l个位置的节点
	void DlistDelete(int l) {
		if (l > len) Log::Error("List length exceeded!");
		if (l < 0) Log::Error("invalid subscript!");

		curr = GetElem(l);

		if (l == len) {
			tail = curr->prior;
			curr->prior->next = nullptr;
		}
		else {
			curr->next->prior = curr->prior;
			curr->prior->next = curr->next;
		}

		len--;
	}

	//头插建立链表
	void HeadInsert(E v) {
		curr = new DNode<E>(v);
		if (len == 0) {
			tail = curr;
		}

		curr->next = head->next;
		curr->prior = head;
		head->next = curr;
		if (len >= 1) {
			curr->next->prior = curr;
		}
		
		len++;
	}

	//尾部删除
	void TailDelete() {
		DlistDelete(len);
	}


};