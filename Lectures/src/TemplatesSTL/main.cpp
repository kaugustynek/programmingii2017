// TemplatesSTL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <string>
#include <map>
#include <deque>
#include <set>

void ShowVector(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
}

void ShowList(list<int> v)
{
    for (list<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
}

void VectorsDemo()
{
    //  Vectors are sequence containers representing arrays that can change in size.
    // constructors used in the same order as described above:
    vector<int> first;                                // empty vector of ints
    vector<int> second(4, 100);                       // four ints with value 100
    vector<int> third(second.begin(), second.end());  // iterating through second
    vector<int> fourth(third);                        // a copy of third

                                                      // the iterator constructor can also be used to construct from arrays:
    int tab[] = { 16,2,77,29 };
    int size = sizeof(tab) / sizeof(int);
    vector<int> fifth(tab, tab + size);

    cout << "The contents of fifth are:";
    ShowVector(fifth);

    // it is possible to iterate over reverse array

    cout << "The contents of inverse fifth are:";
    for (auto it = fifth.rbegin(); it != fifth.rend(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    fifth.push_back(100);
    cout << "Push 100 after last element: " << endl;
    ShowVector(fifth);

    fifth.pop_back();
    cout << "Remove last element: " << endl;
    ShowVector(fifth);

    cout << "Show the current size of the vector: ";
    cout << fifth.size() << endl;

    fifth.resize(10);

    cout << "After resizing: ";
    cout << fifth.size() << endl;

    // It throws exception
    fifth[10] = 20;

    // more information 
    //http://www.cplusplus.com/reference/vector/vector/
}

void ListsDemo()
{
    //Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence, and iteration in both directions.
    //List containers are implemented as doubly - linked lists; Doubly linked lists can store each of the elements they contain in different and unrelated storage locations.The ordering is kept internally by the association to each element of a link to the element preceding it and a link to the element following it.

    // Oznacza to, ¿e elementy listy nie s¹ u³o¿one kolejno w komórkach pamiêci
    // Konstruktory s¹ podobne, jak w przypadku wektora.
    list<int> mylist(2, 100);         // two ints with a value of 100

                                      // istnieje mo¿liwoœæ dodawania (usuwania) elementów na pocz¹tek listy
    mylist.push_front(200);
    mylist.push_front(300);

    cout << "mylist contains:";
    ShowList(mylist);

    mylist.resize(5, 20);
    cout << "after resizing:";
    ShowList(mylist);

    // operacje
    mylist.sort();
    cout << "after sorting:";
    ShowList(mylist);

    mylist.reverse();
    cout << "after reversing:";
    ShowList(mylist);

    mylist.push_back(20);

    mylist.unique();
    cout << "unique list of elements:";
    ShowList(mylist);

    int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int size = sizeof(tab) / sizeof(int);
    mylist = list<int>(tab, tab + size);

    cout << "new list:";
    ShowList(mylist);

    // usuniêcie elementów parzystych
    mylist.remove_if([](const int& value) { return value % 2 == 0; });
    cout << "after removing:";
    ShowList(mylist);

    // other examples see http://www.cplusplus.com/reference/list/list/?kw=list
}

void MapsDemo()
{
    // lub te¿ inaczej tablica asocjacyjna lub s³ownik

    map<string, int> first;

    first["dog"] = 10;
    first["cat"] = 20;
    first["snake"] = 50;
    first["giraffe"] = 70;

    map<string, int> second(first.begin(), first.end());
    map<string, int> third(second);

    third["duck"] = 30;

    cout << third["giraffe"] << endl;

    for each (auto item in third)
    {
        cout << item.first << ": " << item.second << endl;
    }

    cout << "Sprawdzamy czy element o danym kluczu istnieje " << endl;

    string keys[] = { "cat", "dog", "snake", "bird" };
    for (auto key : keys)
    {
        cout << "-----------" << endl;
        cout << "\t" << key << ": " << first.count(key) << endl;

        if (first.count(key) > 0)
        {
            cout << "\t" << "value = " << first.find(key)->second << endl;
        }
    }

    multimap<string, int> multi(first.begin(), first.end());

    // mozna dodaæ wiele elementów o tym samym kluczu
    multi.insert(pair<string, int>("dog", 25));

    for (auto key : keys)
    {
        cout << "-----------" << endl;
        cout << "\t" << key << ": " << multi.count(key) << endl;

        if (multi.count(key) > 0)
        {
            cout << "\t" << "value = " << multi.find(key)->second << endl;
        }
    }

    // wiêcej informacji http://www.cplusplus.com/reference/map/map/
}

void DequeDemo()
{
    // Podwójnie zakoñczona kolejka
    // There are very similar to vector, but
    // vectors use a single array that needs to be occasionally reallocated for growth, 
    // the elements of a deque can be scattered in different chunks of storage, 
    // with the container keeping the necessary information internally to provide direct access 
    // to any of its elements
    // constructors used in the same order as described above:
    deque<int> first;                                // empty deque of ints
    deque<int> second(4, 100);                       // four ints with value 100
    deque<int> third(second.begin(), second.end());  // iterating through second
    deque<int> fourth(third);                       // a copy of third

                                                    // the iterator constructor can be used to copy arrays:
    int myints[] = { 16,2,77,29 };
    deque<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

    cout << "The contents of fifth are:";
    for (deque<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        cout << ' ' << *it;

    cout << '\n';

    // wiêcej informacji http://www.cplusplus.com/reference/deque/deque/

    // analogicznie multiset pozwala na dodawanie wielu kluczy
}

void SetDemo()
{
    // Cechy kontenera
    // - Associative
    //   Elements in associative containers are referenced by their key and not by their absolute position in the container.
    // - Ordered
    //    The elements in the container follow a strict order at all times.All inserted elements are given a position in this order.
    // - Set
    //    The value of an element is also the key used to identify it.
    // - Unique keys
    //    No two elements in the container can have equivalent keys.
    // - Allocator - aware
    //    The container uses an allocator object to dynamically handle its storage needs.
    set<int> first;                           // empty set of ints

    int myints[] = { 10,20,30,40,50,50 };
    int size = sizeof(myints) / sizeof(int);
    set<int> second(myints, myints + size);        // range

    set<int> third(second);                  // a copy of second

    set<int> fourth(second.begin(), second.end());  // iterator ctor.

    cout << "Elementy zbioru: " << endl;
    for (auto item : second)
    {
        cout << item << endl;
    }
    // nie mo¿na dodawaæ duplikatów

    second.erase(second.find(20), second.find(40));
    cout << "Elementy zbioru po skasowaniu: " << endl;
    for (auto item : second)
    {
        cout << item << endl;
    }

    // wiecej informacji http://www.cplusplus.com/reference/set/set/
}

int main()
{
    //VectorsDemo();
    //ListsDemo();
    //MapsDemo();
    //DequeDemo();
    SetDemo();

    // 8. Stack
    // 9. Queue

    return 0;
}

