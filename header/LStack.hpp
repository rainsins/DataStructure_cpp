#pragma once
#include "Node.hpp"
#include "myerror.hpp"

template <class E> class LStack {
private:
	Node<E>* head;
	Node<E>* curr;

	void init() {
		head = curr = new Node<E>();
	}

public:
	LStack(){
		init();
	};

	~LStack() {
		delete head;
	}

	//入栈
	void Push(E& v) {
		Node<E>* tem = new Node<E>(v);
		curr = head->next;
		head->next = tem;
		tem->next = curr;
	}

	//出栈
	E Pop() {
		if (head->next != nullptr) {
			curr = head->next;
			head->next = curr->next;
			E a = curr->element;
			delete curr;
			return a;
		}
		else {
			Log::Error("Stack is empty");
		}
	}

	//得到栈顶
	E& GetTop() {
		if (Empty()) {
			Log::Error("Stack is empty");
		}
		else {
			return head->next->element;
		}
	}

	//是否栈空
	bool Empty() {
		if (head->next == nullptr) {
			return true;
		}
		return false;
	}
};