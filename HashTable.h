#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <cfloat>
#include "Element.h"
using namespace std;

class Element;

class HashTable
{
private:
    int max_load = 100;
    vector<list<Element>> hashtable;

public:
    //Описание: Конструктор по умолчанию, который создаёт хэш-таблицу на 100 ячеек.
    HashTable();

    //Описание: Функция, которая определяет заполненность хэш-таблицы
    bool empty() { return hashtable.empty(); }

    //Описание: Хэш-функция, которая преобразует полученные ключи в индексы хэш-таблицы 
    static int hashfunction(string key);

    //Описание: Функция вставки нового значения в хэш-таблицу
    void insert(string key, string value);

    //Описание: Функция удаления значения в хэш-таблицу
    void erase(string key, string value);

    //Описание: Функция, которая производит поиск значения по введенному ключу
    string get_value(string key);

    //Описание: Функция которая выводит хэш-таблицу в консоль
    void print_table();

    //Описание: Функция,которая заполняет хэш-таблицу псевдорандомными значениями 
    void FillHashTable(const int N = 100);
};


#endif
