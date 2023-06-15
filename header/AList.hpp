#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class E> class AList {
private:
	E* data;
	E* old;
	int len;
	int size;

	//算法实现的中间变量
	int tem;

	void init() {
		cout << "请输入开辟数组的长度：" << endl;
		cin >> size;
		data = new E[size];
		len = 0;
	}

	void copy_all() {
		old = data;
		size = size * 2;
		data = new E[size];
		for (int i = 0; i < len; i++) {
			data[i] = old[i];
		}
	}

public:
	AList() {
		init();
	}

	~AList() {
		delete[] data;
	}

	int Length() {
		return len;
	}

	bool ListInsert(int p, E e) {
		if (p <= 0 || p > len + 2) return false;
		tem = len;
		if (p == len + 1) data[p] = e;
		while (p <= tem)
		{
			data[tem] = data[tem - 1];
			tem--;
		}
		data[p - 1] = e;
		len++;
		return true;
	}

	void PrintList() {
		tem = 0;
		while (tem < len) {
			cout << data[tem] << ", ";
			tem++;
		}
	}

	void HeadInsert(E v) {
		if (len == size) {
			copy_all();
		}
		ListInsert(1, v);
	}

	void TailInsert(E v) {
		if (len == size) {
			copy_all();
		}
		ListInsert(len + 1, v);
	}

	E Delete(int p) {
		for ( p = p - 1 ; p < len - 1; p++)
		{
			data[p] = data[p + 1];
		}
		len = len - 1;
	}

	//23年数据结构王道书顺序表应用题

	//1. 将顺序表逆置，要求空间复杂度为O(1);
	void SwapElem(E left , E right) {
		tem = data[left];
		data[left] = data[right];
		data[right] = tem;
	}

	void FlipList() {
		int left = 0;
		int right = len - 1;
		while (left < right) 
		{
			SwapElem(left, right);
			left++;
			right--;
		}
	}

	//2. 删除所有值为x的数据元素，时O(n)，空O(1)。
	void DeleteAllValue(E x) {
		size_t left = 0;
		size_t right = 1;
		const int t = len;
		while (right < t)
		{
			if (data[right] == x) {
				len--;
			}
			if (data[left] == x && data[right] != x) {
				data[left] = data[right];
				data[right] = x;
				left++;
				right++;
			}
			else if(data[left] == x && data[right] == x) {
				right++;
			}
			else {
				right++;
				left++;
			}
		}
	}


};