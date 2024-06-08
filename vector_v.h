#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "vector_exception.h"


template<class T>
class Vector {
	private:
		T data[100];
		int size;
	public:
		Vector();
		Vector(int v_size, T value);
		int Size() const;
		T operator[](int index) const;
		T& operator[](int index) ;
		std::string dump(int precision) const;
};

template<class T>
inline Vector<T>::Vector() 
	: size(10)
{
	for(int i = 0; i < size; i++) 
		data[i] = 0;
}

template<class T>
inline Vector<T>::Vector(int v_size, T value)
	: size(v_size)
{
	if (v_size < 0) {
		throw VectorNegativeSize(v_size);
	}
	else if (v_size > 100){
		throw VectorBiggerThanBuffer(v_size);	
	}
	for (int i = 0; i < size; i++) {
		data[i] = value;
	}
}

template<class T>
inline int Vector<T>::Size() const {
	return size;
}


template<class T>
inline T Vector<T>::operator[](int index) const {
	if (index < 0) {
		throw VectorNegativeIndex(index);
	}
	else if (index >= size) {
		throw VectorIndexBiggerThanSize(index);
	}
	return data[index];
}

template<class T>
inline T &Vector<T>::operator[](int index) {
 	if (index < 0) {
		throw VectorNegativeIndex(index);
	}
	else if (index >= size) {
		throw VectorIndexBiggerThanSize(index);
	}
 	return data[index];
}

template<class T>
inline std::string Vector<T>::dump(int precision) const { 
	std::stringstream stream;
	stream << "{";
	
	for (int i = 0; i < Size(); i++) {
		stream << std::setprecision(precision) << data[i];
		if (i != Size() - 1) {
		stream << ", ";
		}
	}
	stream << "}";
	std::string a = stream.str();
	return a;
}
