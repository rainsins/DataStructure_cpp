#pragma once

template <class E> class Node
{
public:
	E element;
	Node<E>* next;

	Node(E e = NULL) {
		element = e;
		next = nullptr;
	}
};

template <class E> class DNode
{
public:
	E element;
	DNode<E>* next;
	DNode<E>* prior;

	DNode(E e = NULL) {
		element = e;
		next = nullptr;
		prior = nullptr;
	}
};