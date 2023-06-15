#pragma once
#include <iostream>
#include "myerror.hpp"
#include "Node.hpp"

template <typename E> class LList
{
private:
	Node<E>* head;
	Node<E>* tail;
	Node<E>* curr;
	int len;
	int defaultSize = 0;

	//初始化链表
	void init() {
		head = curr = tail = new Node<E>();

		len = 0;
	}

	//清理节点
	void clear_all() {
		while (head != nullptr)
		{
			curr = head;
			head = head->next;
			delete curr;
		}
	}


	//得到一个节点
	Node<E>* GetElem(int l) {
		curr = head;
		while (curr != nullptr && l > 0)
		{
			curr = curr->next;
			l--;
		}
		return curr;
	}

public:
	LList() { init(); }
	~LList() { clear_all(); }

	//返回长度
	int Length() const {
		return len;
	}

	//按值查找，找到第一个就返回
	Node<E>* LocateElem(E v) {
		curr = head;
		while (curr != nullptr)
		{
			if (curr->element == v)
				return curr;
			curr = curr->next;
		}
		return nullptr;
	}

	//按位查找
	E FindElem(int l) {
		if (l > len) Log::Error("List length exceeded!");
		if (l < 0) Log::Error("invalid subscript!");
		curr = head;
		while (curr != nullptr && l > 0)
		{
			curr = curr->next;
			l--;
		}
		return curr->element;
	}

	//插入值，返回插入是否成功；
	bool Insert(int l, E v) {
		if (l + 1 > len || l < 0) return false;
		curr = GetElem(l - 1);
		Node<E>* tem = curr;
		curr = new Node<E>();

		curr->element = v;
		curr->next = tem->next;
		tem->next = curr;

		if (l == len + 1) {
			tail = curr;
		}

		len++;
		return true;
	}

	//删除值，返回删除的元素值
	E& Delete(int l) {
		if (l > len) Log::Error("List length exceeded!");
		if (l < 0) Log::Error("invalid subscript!");
		curr = GetElem(l - 1);
		E tem = curr->next->element;
		curr->next = curr->next->next;
		if (l == len) {
			tail = curr;
		}
		len--;
		return tem;
	}

	//输出表
	void PrintList() {
		curr = head;
		while (curr != nullptr)
		{
			std::cout << curr->element << ", ";
			curr = curr->next;
		}
	}

	//判空
	bool Empty() {
		if (head->next == nullptr) return true;
		return false;
	}

	//清除所有节点
	void Clear() {
		clear_all();
		init();
	}

	//头插法建立单链表
	void HeadInsert(E v) {
		Node<E>* tem = head->next;
		Node<E>* new_node = new Node<E>(v);
		new_node->next = tem;
		head->next = new_node;
		if (len == 0) {
			tail = new_node;
		}
		len++;
	}

	//尾插法建立单链表
	void TailInsert(E v) {
		Node<E>* new_node = new Node<E>(v);
		tail->next = new_node;
		len++;
	}


	//做题添加的方法
	void remove_all_value(E& v) {
		
	};
};