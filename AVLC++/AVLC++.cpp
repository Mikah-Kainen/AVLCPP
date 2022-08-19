// AVLC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.cpp"

int main()
{
    std::cout << "Hello World!\n";
    Tree<int> tree;
    tree.Add(5);
    tree.Add(15);
    tree.Add(20);
    tree.Add(10);
    tree.Add(8);
    tree.Add(12);

    //tree.FakeAdd(5);
    //tree.FakeAdd(10);
    //tree.FakeAdd(8);
    //tree.FakeAdd(12);
    //auto result = tree.Rotateleft(tree.head);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
