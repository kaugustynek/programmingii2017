// TemplatesSTL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

int main()
{
    // 1. Vector
    //  Vectors are sequence containers representing arrays that can change in size.
    // constructors used in the same order as described above:
    vector<int> first;                                // empty vector of ints
    vector<int> second(4, 100);                       // four ints with value 100
    vector<int> third(second.begin(), second.end());  // iterating through second
    vector<int> fourth(third);                        // a copy of third

                                                      // the iterator constructor can also be used to construct from arrays:
    double tab[] = { 16,2,77,29 };
    int size = sizeof(tab) / sizeof(double);
    vector<int> fifth(tab, tab + size);

    cout << "The contents of fifth are:";
    for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    // 2. List
    // 3. Map
    // 4. Multimap
    // 5. Deque
    // 6. Set
    // 7. Multiset
    // 8. Stack
    // 9. Queue

    return 0;
}

