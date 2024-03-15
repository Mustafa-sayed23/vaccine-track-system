#pragma once
#include<iostream>
#include<string>
using namespace std;
template <class T>
class ArrayList
{
	T* arr;
	int size, count;
public:
	ArrayList();
	~ArrayList();
	int Length();
	void Expand();
	void Append(T &val);
	T At(int pos);
	void display();
	void deleteAt(int pos);
	void insertAt(int pos, T val);

};


