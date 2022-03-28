#include <iostream>
#include <fstream>
#include "Element.h"
#include "HashTable.h"
#include "ArrayParent.h"
#include <chrono>


using namespace std;
using namespace chrono;

int main()
{
    
    setlocale(LC_ALL, "Russian");
    cout << "Моделирование хэш-таблицы" << endl;
    int choice = 0;
    HashTable t, t1, t2, t3;
    system_clock::time_point start;
    system_clock::time_point end;
    cout << "Сравнить скорость работы базовы методов:"
        <<endl<<"при 10 элементах [1]," 
        <<endl<<"при 10.000 элементах [2],"
        <<endl<<"при 1.000.000 элемтах [3],"
        <<endl<<endl<<"Использовать базовые методы [4].";
    cout << endl << "Введите число" << endl;
    cin >> choice;
    if ((choice != 1) && (choice != 2) && (choice != 3)&&(choice !=4))
    {
        cout << "Введено некоректное значение. Работа программы остановлена";
        return 0;
    }
    switch (choice)
    {
    case 1:
    {
        t.FillHashTable(10);
        cout << "Hash-table"<<endl;
        system_clock::time_point start = system_clock::now();
        t.insert("Alex", "171-23-26");
        system_clock::time_point end = system_clock::now();
        cout << "Time of insert in hash-table with 10 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = system_clock::now();
        t.get_value("Alex");
        end = system_clock::now();
        cout << "Time of search in hash-table with 10 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = system_clock::now();
        t.erase("Alex", "171-23-26");
        end = system_clock::now();
        cout << "Time of delete in hash-table with 10 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;
        cout << endl;

        cout << "Array"<<endl;
        ArrayParent Array(10);
        start = system_clock::now();
        Array.InsertAt(23, 5);
        end = system_clock::now();
        cout << "Time of insert in Array with 10 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = system_clock::now();
        Array.Find(23);
        end = system_clock::now();
        cout << "Time of find in Array with 10 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = system_clock::now();
        Array.RemoveAt(5);
        end = system_clock::now();
        cout << "Time of delete in Array with 10 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;
        break;
    }
    case 2:
    {
        t1.FillHashTable(10000);

        cout << "Hash-table" << endl;
        start = system_clock::now();
        t1.insert("Alex", "171-23-26");
        end = system_clock::now();
        cout << "Time of insert in hash-table with 10.000 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = system_clock::now();
        t1.get_value("Alex");
        end = system_clock::now();
        cout << "Time of search in hash-table with 10.000 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = system_clock::now();
        t1.erase("Alex", "171-23-26");
        end = system_clock::now();
        cout << "Time of delete in hash-table with 10.000 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;
        cout << endl;

        cout << "Array" << endl;
        ArrayParent Array1(10000);
        start = system_clock::now();
        Array1.InsertAt(23, 6666);
        end = system_clock::now();
        cout << "Time of insert in Array with 10.000 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = system_clock::now();
        Array1.Find(2789);
        end = system_clock::now();
        cout << "Time of find in Array with 10.000 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = system_clock::now();
        Array1.RemoveAt(9098);
        end = system_clock::now();
        cout << "Time of delete in Array with 10.000 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;
        break;
    }

    case 3:
    {
        t2.FillHashTable(1000000);

        cout << "Hash-table" << endl;
        start = system_clock::now();
        t2.insert("Alex", "171-23-26");
        end = system_clock::now();
        cout << "Time of insert in hash-table with 1.000.000 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = system_clock::now();
        t2.get_value("Alex");
        end = system_clock::now();
        cout << "Time of search in hash-table with 1.000.000 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = system_clock::now();
        t2.erase("Alex", "171-23-26");
        end = system_clock::now();
        cout << "Time of delete in hash-table with 1.000.000 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;
        cout << endl;

        cout << "Array" << endl;
        ArrayParent Array2(1000000);
        start = system_clock::now();
        Array2.InsertAt(2356, 25);
        end = system_clock::now();
        cout << "Time of insert in Array with 1.000.000 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = system_clock::now();
        Array2.Find(9356);
        end = system_clock::now();
        cout << "Time of find in Array with 1.000.000 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = system_clock::now();
        Array2.RemoveAt(500000);
        end = system_clock::now();
        cout << "Time of delete in Array with 1.000.000 elements: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;
        
        break;
    }
    case 4:
    {
        t3.FillHashTable(10);

        t3.print_table();

        string key, value;
        cout << "Вставка элемента" << endl;
        cout << "Введите ключ" << endl;
        cin >> key;
        cout << "Введите значение" << endl;
        cin >> value;
        t3.insert(key, value);

        t3.print_table();

        cout << "Удаление элемента" << endl;
        cout << "Введите ключ" << endl;
        cin >> key;
        cout << "Введите значение" << endl;
        cin >> value;
        t3.erase(key,value);

        t3.print_table();
        break;
    }
   
    }
}
