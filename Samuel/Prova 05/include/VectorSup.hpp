#ifndef VECTORSUP_H
#define VECTORSUP_H

#include "Produto.hpp"
#include <iostream>
template <class T>
class VectorSup {
	private:
		void realocate(){
			actualSize = actualSize * 2;
			T* newElements = new T[actualSize];
			
			for (size_t i = 0; i <= lastIndex; i++){
				newElements[i] = elements[i];
			}
			//delete elements
			elements = newElements;
			//delete newElements
		}
		void adjust(size_t index){
			for (size_t i = index; i < lastIndex; i++){
				elements[i] = elements[i + 1];
			}
			elements[lastIndex] = nullptr;
		}

		bool isFull(){
			if (lastIndex >= actualSize -1){

				return true;
			}
			return false;
		}

	public:
		int lastIndex = -1;
		int actualSize;
		T *elements;

		VectorSup(){
			this->actualSize = 10;
			this->elements = new T[10];
		};
		~VectorSup(){
			//delete elements;
		};

		T& getLastElement(){
			return elements[lastIndex];
		}
		T& getFirstElement();
		T& getElementIndex(size_t index){
			if (index > lastIndex){
				throw "Não existe um elemento nessa posição!";
			}
			return elements[index];
		}

		T copyElementIndex(size_t index){
			if (index > lastIndex){
				throw "Não existe um elemento nessa posição!";
			}
			return elements[index];
		}

		bool isEmpty();

		void addElement(T element){
			if (isFull()){
				realocate();
				lastIndex++;
				elements[lastIndex] = element;
			} else {
				lastIndex++;
				elements[lastIndex] = element;
			}
		}
		//Caso sobre tempo, criar o desalocate
		void rmElementIndex(size_t index){
			elements[index] = NULL;
			adjust(index);
		}
		void rmLastElement();
};

#endif