#include "HashTable.h"
#include <vector>
#include <string>
#include <list>

using namespace std;

HashTable::HashTable()
{
    hashtable.resize(1000);
}

void HashTable::print_table()
{
    Element someel("0", "0");

    for (auto it1 = hashtable.cbegin(); it1 != hashtable.cend(); ++it1)
    {
        if ((*it1).empty()) continue;
        else
            for (auto it2 = (*it1).cbegin(); it2 != (*it1).cend(); ++it2)
                cout << (*it2) << " with hash " << hashfunction((*it2).get_key())<<endl;
    }
    cout << endl;
}

int HashTable::hashfunction(string key)
{
    int hash = 0;
    for (size_t i = 0; i < key.size(); ++i)
    {
        int tmp = key[i];
        tmp = tmp << (i * 8 % 24);
        hash = hash ^ tmp;
    }
    return hash % 100;
}

void HashTable::insert(string key, string value)
{
    int index = hashfunction(key);

    Element someElement(key, value);
    hashtable[index].push_front(someElement);
    //hashtable[index].unique();
}

void HashTable::erase(string key, string value)
{
    int index = hashfunction(key);

    Element someelement(key, value);

    for (auto it = hashtable[index].cbegin(); it != hashtable[index].cend(); ++it)
        if (*it == someelement) {
            hashtable[index].erase(it);
            break;
        }
}

string HashTable::get_value(string key)
{
    int index = hashfunction(key);

    for (auto it = hashtable[index].cbegin(); it != hashtable[index].cend(); ++it)
        if ((*it).get_key() == key)
        {
            return (*it).get_value();
        }

    cerr << "Nothing was found";
    return 0;
}


void HashTable::FillHashTable(int N)
{
        srand(unsigned(time(NULL)));
        string* arr = new string [N];
        string* ptr = new string [N];
        string key;
        string value1;
      
        char sym = '/';
        for (int j = 0; j < N; ++j) {
            key = "";
            for (int i = 0; i < 2; ++i) {
                sym = '/';

                while ((sym < '0') || (sym > '9' && sym < 'A') || (sym > 'Z' && sym < 'a') || (sym > 'z'))
                    sym = static_cast<char> (rand() % 123 + 48);

                key += sym;
            }
            arr[j] = key;
        }

        int value = 0;
        for (int i = 0; i < N-1; i++)
        {
                value = rand() % 10000;
                ptr[i] = to_string(value);
        }

        for (int i = 0; i < N; i++)
        {
            key ="";
            value1 = "";
            key = arr[i];
            value1 = ptr[i];
            insert(key, value1);
        }


}

