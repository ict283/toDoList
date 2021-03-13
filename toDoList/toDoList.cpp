// For review purposes only! Does not represent the actual solution!

#include "toDoList.h"

ToDoList::ToDoList()
{

}

ToDoList::~ToDoList()
{

}

void ToDoList::run()
{
        store(read("to_do_data.txt"));
        display();

}

string ToDoList::read(const string fileName)
{
        ifstream infile (fileName);

        if(!infile.is_open())
        {
                cout<<"Error: File Not Found - "<<fileName<<endl;
                return NULL;
        }

        string fileStreamData;
        getline(infile, fileStreamData);
        return fileStreamData;

}

void ToDoList::store(string fileStreamData)
{
        istringstream stringStream {fileStreamData}; //stringify

        string item;
        string taskDay="";
        int taskNum=1;
        vector<Task> * taskList = new vector<Task>();

        while (getline(stringStream,item,','))
        {
                if(item[0]=='#')
                {
                        taskDatabase.insert(*taskList); //store current vector
                        taskList = new vector<Task>(); //create a new vector
                        taskDay= item.substr(1,item.length());
                        taskNum =1;
                }
                else
                {
                        Task task;
                        task.key = taskDay;
                        task.num = taskNum++;
                        task.taskDescription = item;
                        taskList->push_back(task);
                }
        }

}

void ToDoList::display()
{
        taskDatabase.print();
}

ostream& operator << (ostream &os, const vector<Task> taskList)
{
        string currentDay="";

        for(Task t : taskList)
        {
                if(currentDay!=t.key)
                {
                        cout<<endl;
                        currentDay=t.key;
                        cout<<"=="<<currentDay<<"=="<<endl;
                }

                cout<<t.num<<"-"<<t.taskDescription<<endl;
        }

        return os;
}
