#include "ArrayParent.h"
#include <iostream>
#include <ctime>

using namespace std;

ArrayParent::ArrayParent(int Dimension)
{
	ptr = new int[Dimension];
	capacity = Dimension;
	count = 0;
}

ArrayParent::ArrayParent(int SonCount, int* SonPtr)
{
	count = SonCount;
	capacity = SonCount;

	ptr = new int[capacity];
	for (int i = 0; i < SonCount; i++)
		ptr[i] = SonPtr[i];
}

ArrayParent::~ArrayParent()
{
	if (ptr != NULL)
	{
		delete[] ptr;
		ptr = NULL;
	}
}

ArrayParent::ArrayParent(const ArrayParent& V)
{
	count = V.count;
	capacity = V.capacity;

	ptr = new int[V.capacity];

	for (int i = 0; i < V.count; i++)
		ptr[i] = V.ptr[i];
}

// Оператор [], для возвращения индекса элемента
int ArrayParent::operator [] (int index)
{
	return ptr[index];
}

//Оператор присваивания 
ArrayParent& ArrayParent::operator=(const ArrayParent& V)
{
	count = V.count;
	capacity = V.capacity;

	ptr = new int[V.capacity];
	for (int i = 0; i < V.count; i++)
		ptr[i] = V.ptr[i];
	return *this;
}

//Функция вывода
void ArrayParent::print()
{
	cout << "\nMyArrParent, size: " << capacity << ", values: {";
	int i = 0;
	for (i = 0; i < capacity; i++)
	{
		cout << ptr[i]<<" ";
		//if (i != capacity - 1)
			//cout << ", ";
	}
	cout << "}";
}

//заполнение массива рандомными числами
void ArrayParent::Fill()
{
	srand((unsigned)time(NULL));

	double value = 0;
	for (int i = 0; i < capacity; i++)
	{
			value = rand() % 10000;
			ptr[i] = value;
	}
}

//Функция поиска
int ArrayParent::Find(double value)
{
	for (int i = 0; i < capacity; i++)
	{ 
		if (ptr[i] == value)
			return i;
	}
	
	return -1;
}

//добавление в конец нового значения
void ArrayParent::push_back(int value)
{
	if (count < capacity)
	{
		ptr[count] = value;
		count++;
	}
}

//Функция добавления
void ArrayParent::InsertAt(int value, int index)
{
	for (int i = 0; i < index; i++)
		{
			ptr[i] = ptr[i+1];
		}
			ptr[index] = value;
}

//удаление элемента
void ArrayParent::RemoveAt(int index)
{
	for (int i = index; i < capacity - 1; i++)
		ptr[i] = ptr[i + 1];

	capacity--;
}

