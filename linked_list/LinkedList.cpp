#include "LinkedList.h"
#include <deque>
#include <iostream>
#include "../exceptions/exceptions.h"

namespace FSN {
    LinkedList::LinkedList() {
        this->head = nullptr;
        this->size = 0;
    }

    int LinkedList::getSize() {
        return this->size;
    };

    void  LinkedList::print() {//nice
        Node *temp = this->head;


        if(this->isEmpty()) {
            std::cout << "Empty List\n";
            EmptyException("List is empty");
        } else {
            try {
                std::ofstream fout;
                fout.open("../txt/output.txt", std::ios_base::app);
                if (fout.is_open()) {
                    fout << "\n";
                    while(temp != nullptr) {
                        fout << "data: " << temp->data << " next: " << temp->next << " -> ";
                        temp = temp->next;
                    }
                }
                fout.close();
            }
            catch (...) {

            }
            temp = this->head;
            while(temp != nullptr) {
                std::cout << "data: " << temp->data << " next: " << temp->next << " -> ";
                temp = temp->next;
            }
            std::cout << "null\n";
        }
    }


    void LinkedList::addItem(double num) {
        Node *temp = new Node(num);
        temp->next = head;
        head = temp;
        this->size++;
    }

    void LinkedList::deleteItem(int pos) {
        if (this->isEmpty()) {
            std::cout << "Empty array, you can`t delete anything\n";
            EmptyException("List is empty");
            return;
        }
        if (pos < 0 || pos > this->size) {
            std::cout << "Invalid number\n";
        }

        Node *temp, *prev, *ptrNode;

        if (pos == 1) {
            temp = this->head;
            this->head = head->next;
            delete temp;
            this->size--;
        } else if (pos == this->size) {
            prev = this->head;
            while (prev->next->next != nullptr) {
                prev = prev->next;
            }
            temp = prev->next;
            prev->next = nullptr;
            delete temp;
            this->size--;
        } else {
            prev = this->head;
            int i = 1;
            while (i < (pos - 1)) {
                prev = prev->next;
                i++;
            }
            temp = prev->next;
            prev->next = prev->next->next;
            delete temp;
            this->size--;
        }
    }

    void LinkedList::sort() {
        if (this->isEmpty()) {
            std::cout << "This list is empty";
            return;
        }

        Node *cur = this->head;
        double plus[100];
        double minus[100];
        int minusIter = 0;
        int plusIter = 0;

        while(cur != nullptr) {
            if (cur->data >= 0) {
                plus[plusIter] = cur->data;
                plusIter++;
            } else {
                minus[minusIter] = cur->data;
                minusIter++;
            }
            cur = cur->next;
        }

        cur = this->head;

        for ( int i = 0; i < minusIter ;i++) {
            cur->data = minus[i];
            cur = cur->next;
        }

        for ( int i = 0; i < plusIter ;i++) {
            cur->data = plus[i];
            cur = cur->next;
        }
    }

    bool LinkedList::isEmpty() {
        return (this->head == nullptr);
    }
};
