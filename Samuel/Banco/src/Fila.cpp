#include "../include/Fila.hpp"

template <class T>
Fila<T>::Fila(int size){

	this->size = size;
	this->lastItemIndex = -1;
	this->elements = new T[size];
}

template <class T>
Fila<T>::~Fila(){
	delete elements;
}

template <class T>
T Fila<T>::getFirstItem(){
	return elements[0];
}

template <class T>
T Fila<T>::removeFirstItem(){
	T removedItem;
	removedItem = elements[0];

	for (size_t i = 1; i <= lastItemIndex; i++){
		elements[i - 1] = elements[i];
	}
	delete elements[lastItemIndex];
	lastItemIndex--;
	return removedItem;
}

template <class T>
void Fila<T>::addItem(T item){
	if (lastItemIndex < size){
		lastItemIndex++;
		elements[lastItemIndex] = item;
	}
}

template <class T>
bool Fila<T>::isEmpty(){
	if (lastItemIndex == -1){
		return true;
	} else {
		return false;
	}
}