#ifndef FILA_H
#define FILA_H

#include <string>

template <class T>
class Fila{
	private :
		int size;
		int lastItemIndex;
		T* elements;
	public:
		Fila(int size);
		~Fila();
		T getFirstItem();
		T removeFirstItem();
		void addItem(T item);
		bool isEmpty();
};

#endif