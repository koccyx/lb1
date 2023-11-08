#ifndef TIZD_LINKEDLIST_H
#define TIZD_LINKEDLIST_H
#include "Node.h"

namespace FSN {
    class LinkedList {
    private:
        Node *head;
        int size;
    public:
        LinkedList();
        int getSize();
        void addItem(double);
        void deleteItem(int);
        bool isEmpty();
        void print();
        void sort();
    };
};


#endif //TIZD_LINKEDLIST_H
