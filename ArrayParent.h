#ifndef ARRAYPARENT_H
#define ARRAYPARENT_H

#include <iostream>
#include <ctime>

using namespace std;
class ArrayParent
{
protected:
	//сколько памяти выделено
	int capacity;
	//количество элементов
	int count;
	//массив
	int* ptr;
public:
	//конструкторы и деструктор
	ArrayParent(int Dimension);

	//конструктор принимает существующий массив
	ArrayParent(int SonCount, int* SonPtr);

	//конструктор копий 
	ArrayParent(const ArrayParent& V);

	~ArrayParent();

	int operator[] (int index);
	ArrayParent& operator=(const ArrayParent& V);
	void print();
	void push_back(int value);
	void Fill();
	int Find(double value);
	void InsertAt(int value, int index = -1);
	void RemoveAt(int index);
};

#endif
