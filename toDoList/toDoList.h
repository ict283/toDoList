// For review purposes only! Does not represent the actual solution!

#ifndef toDoList_h
#define toDoList_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include "list.h"

using namespace std;

struct Task
{
        string key;

        int num;

        string taskDescription;
};


class ToDoList
{

public:

ToDoList();

~ToDoList();

void run();

string read(const string fileName);

void store(string fileStreamData);

void display();


private:

Linkedlist<vector<Task> > taskDatabase; //Linked list of vectors

};

ostream& operator << (ostream &os, const vector<Task> taskList);


#endif /* toDoList_h */
