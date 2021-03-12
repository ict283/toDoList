// For review purposes only! Does not represent the actual solution!

#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template <class Type>
struct node
{
        Type data;

        node <Type> * next;
};


template <class Type>
class Linkedlist
{

public:

Linkedlist();

~Linkedlist();

void insert (const Type & item);

void print();


private:

int size;

node<Type> * first, * last;

};


/*Implementation*/

template <class Type>
Linkedlist<Type>::Linkedlist()
{

        first = NULL;

        last = NULL;

        size = 0;
}

template <class Type>
Linkedlist<Type>::~Linkedlist()
{
        node<Type> * temp;

        while (first!=NULL) {

                temp=first;

                first = first->next;

                delete temp;
        }
        last = NULL;

        size = 0;
}

template <class Type>
void Linkedlist<Type>::insert (const Type & item)
{
        node<Type> * newNode;

        newNode = new node<Type>;

        newNode->data = item;

        newNode->next = NULL;

        if (first == NULL)
        {
                first = newNode;

                last = newNode;

                size++;

        }
        else
        {
                last->next=newNode;

                last=newNode;

                size++;
        }
}

template <class Type>
void Linkedlist<Type>::print()
{

        node<Type> * current;

        current = first;

        while (current!=NULL)
        {

                cout<<current->data<<" ";

                current = current->next;
        }
}

#endif /* LIST_h */
