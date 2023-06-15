#pragma once
#include "myerror.hpp"

template <class E> class AStack {
private:
	E* data;
	int top;
	int maxsize;

	E temp;

	void init(int size) {
		top = 0;
		data = new E[size];
	}

	void clear_all() {
		delete[] data;
	}

public:
	AStack(int size = 100) {
		maxsize = size;
		init(maxsize);
	}

	~AStack() {
		clear_all();
	}

	bool Push(E& v) {
		if (top < maxsize) {
			data[top] = v;
			top++;
			return true;
		}
		return false;
		
	}

	E& Pop() {
		temp = GetTop();
		if (!StackEmpty()) {
			top--;
		}
		return temp;
	}

	bool StackEmpty() {
		if (top == 0) {
			return true;
		}
		return false;
	}

	E& GetTop() {
		if (StackEmpty()) {
			Log::Error("Stack is empty!");
		}
		return data[top - 1];
	}
};
