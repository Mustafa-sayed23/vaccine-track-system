#include "ArrayList.h"
#include<iostream>
#include<string>
using namespace std;
template<class T>
ArrayList<T>::ArrayList() {

	count = 0;
	size = 10;
	arr = new T[size];
}
template<class T>
ArrayList<T>::~ArrayList() {
	//delete count;
	//delete size;  
	delete[]arr;
}
template<class T>
T ArrayList<T>::At(int pos) {

	return arr[pos];
}
template<class T>
void ArrayList<T>::Append(T &val) {

	if (count == size)
		Expand();
	arr[count] = val;
	count++;

}
template<class T>
int ArrayList<T>::Length() {
	return count;

}

template<class T>
void ArrayList<T>::Expand() {
	size *= 2;
	T* temp = new T[size];
	for (unsigned int i = 0; i < count; i++)
		temp[i] = arr[i];
	delete[]arr;
	arr = temp;
}

template<class T>
void ArrayList<T>::deleteAt(int pos) {
	//assert(pos >= 0 && pos < count);
	for (int i = pos; i < count - 1; i++)
		arr[i] = arr[i + 1];
	count--;

}
template<class T>
void ArrayList<T>::insertAt(int pos, T val) {
	//assert(pos >= 0 && pos < count);
	if (count == size)
		Expand();
	for (int i = count; i > pos; i--)
		arr[i] = arr[i - 1];
	arr[pos] = val;
	count++;

}

template<class T>
void ArrayList<T>::display() {
	for (int i = 0; i < count; i++)
		cout << arr[i] << endl;

}

