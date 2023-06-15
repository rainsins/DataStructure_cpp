#pragma once
#include "Node.hpp"
#include "myerror.hpp"

template <class E> class LQueue {
private:
	Node<E>* front, rear, temp;
	
	void init() {
		front = rear = new Node<E>();
	}

	void clear() {
		delete front;
	}

public:
	LQueue() {
		init();
	}

	~LQueue() {
		clear();
	}

	bool IsEmpty() {
		if (front == rear) {
			return true;
		}
		return false;
	}

	void EnQueue(E &v) {
		temp = new Node<E>(v);
		rear->next = temp;
		rear = temp;
	}

	E& DeQueue() {
		if (front->next == nullptr) {
			Log::Error("Queue is empty!");
		}
		temp = front->next;
		E value = temp->element;
		front->next = temp->next;
		if (rear == temp) {
			rear = front;
		}
		delete temp;
		return value;
	}
};