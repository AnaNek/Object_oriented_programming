#include <iostream>

using namespace std;

#include "_list.hpp"

int main()
{
    List<int> l = {-1, 0, 1};

    auto i = l.begin();

    std::cout << bool(i);

    List<int> list = List<int>(l.begin(), l.end());
    std::cout << list;
    List<int> list1;
    List<int> list2;

        int *array = new int[4];
        for (int i = 0; i < 4; i++)
        {
            array[i] = i;
        }
        list2.append(array, 4);
        std::cout << list2;
        delete [] array;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(0);
    std::cout << list;

    list1.pushFront(7);
    list1.pushFront(9);
    list1.pushFront(3);
    list1.pushFront(1);
    list1.pushFront(9);

    std::cout << "insert\n";
    l.insert(i, 2);
    std::cout << l;

    list.append(list1);

    list += l;
    std::cout << list;

    Iterator<int> iter = list.begin();

    Iterator<int> it = list.begin();

    while (iter != list.end())
    {

        if (*iter % 2 == 0)
            list.remove(iter);
        ++iter;
    }

    std::cout << list;

    list.popFront();
    list.popFront();

    std::cout << list;

    list.clear();
    std::cout << list;

    return 0;
}
