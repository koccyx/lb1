#include "menu/MenuManager.h"
#include "linked_list/LinkedList.h"
#include <iostream>
#include <fstream>
#include "exceptions/exceptions.h"
using namespace std;
using namespace FSN;

LinkedList* lst = new LinkedList();

void sort() {
    lst->sort();
    cout << "1\n";
}

void add() {
    try {
        double num;
        cout << "Input number: ";
        cin >> num;
        lst->addItem(num);
    } catch(...) {
        InputException("Invalid choice, try again\n");
    }
}

void remove() {
    lst->deleteItem(lst->getSize() - 1);
}

void print() {
    lst->print();
    cout << "3\n";
}

void fileTest() {
    int fileIter = 0;
    ifstream fin;
    fin.open("../txt/input.txt");
    double *arr {new double[0]{}};
    try {
    if(!fin.is_open()) {
        cout << "mistake file";
    } else {
        string str;
        while (!fin.eof()) {
            fin >> str;
            lst->addItem(stod(str));
            }
        }
    } catch (string error) {

    }
    fin.close();
    delete[] arr;
}

int main() {
    MenuManager menuManager;
    menuManager.addMenuItem(MenuItem("Add item", add));
    menuManager.addMenuItem(MenuItem("Remove item", remove));
    menuManager.addMenuItem(MenuItem("Print", print));
    menuManager.addMenuItem(MenuItem("Sort", sort));
    menuManager.addMenuItem(MenuItem("Input from file", fileTest));

    menuManager.showMenu();

    return 0;
}
