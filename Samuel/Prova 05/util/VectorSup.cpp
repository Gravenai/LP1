//#include "../include/VectorSup.hpp"

template <class T>
VectorSup<T>::VectorSup(){
	actualSize = 10;
	this->elements = new T[10];
}

template <class T>
VectorSup<T>::~VectorSup(){
	delete elements;
}

// PRIVATE:

template <class T>
void VectorSup<T>::realocate(){
	actualSize = actualSize * 2;
	T* newElements = new T[actualSize];
	for (size_t i = 0; i <= lastIndex; i++){
		newElements[i] = elements[i];
	}
	delete elements;
	elements = newElements;
	delete newElements;
}

template <class T>
void VectorSup<T>::adjust(size_t index){
	for (size_t i = index; i < lastIndex; i++){
		elements[i] = elements[i + 1];
	}
	elements[lastIndex] = nullptr;
}

template <class T>
bool VectorSup<T>::isFull(){
	if (lastIndex >= actualSize -1){
		return true;
	}
	return false;
}

// PUBLIC

template <class T>
T VectorSup<T>::getElementIndex(size_t index){
	if (index >= lastIndex){
		return NULL;
	}
	return elements[index];
}

template <class T>
T VectorSup<T>::getLastElement(){
	return elements[lastIndex];
}

template <class T>
void VectorSup<T>::addElement(T element){
	if (isFull()){
		realocate();
	} else {
		lastIndex++;
		elements[lastIndex] = element;
	}
}

//Caso sobre tempo, criar o desalocate
template <class T>
void VectorSup<T>::rmElementIndex(size_t index){
	elements[index] = NULL;
	adjust(index);
}