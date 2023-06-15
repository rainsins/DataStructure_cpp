#pragma once
#include "myerror.hpp"


template <class E> class AQueue {
private:
	E* data;
	int front,rear;
	int maxsize;

	void init(int size) {
		maxsize = size;
		front = rear = 0;
		data = new E[size];
	}

	void clear_all() {
		delete[] data;
	}

public:
	AQueue(int size = 20) {
		init(size);
	}

	~AQueue() {
		clear_all();
	}
	//判队空
	bool QueueEmpty() {
		if (front == rear) {
			return true;
		}
		return false;
	}
	//入队
	bool EnQueue(E& v) {
		if (rear <= maxsize) {
			data[rear++] = v;
			return true;
		}
		return false;
	}
	//出队
	E& DeQueue() {
		if (front >= rear) {
			Log::Error("Queue is empty!");
		}
		return data[front++];
	}
	//得到队头
	E& GetHead() {
		if (front >= rear) {
			Log::Error("Queue is empty!");
		}
		return data[rear - 1];
	}
};

//循环队列
template <class E> class CycleAQueue {
private:
	E* data;
	int front, rear;
	int maxsize;
	int size;

	void init(int size) {
		front = rear = 0;
		size = 0;
		maxsize = size;
		data = new E[size];
	}

	void clear_all() {
		delete[] data;
	}
public:
	CycleAQueue(int size = 20) {
		init(size);
	}

	~CycleAQueue() {
		clear_all();
	}

	bool QueueEmpty() const{
		if (size == 0) {
			return true;
		}
		return false;
	}

	bool EnQueue(E &v) {
		if (size >= maxsize) {
			return false;
		}
		data[rear] = v;
		rear = (rear + 1) % maxsize;
		size++;
		return true;
	}

	bool DeQueue() {
		if (size == 0) {
			return false;
		}
		front = (front + 1) % maxsize;
		size--;
		return false;
	}
};

