#include <iostream>

#include "TodoList.h"

using namespace std;

int main(int argc, char* argv[])
{
    TodoList todoList;

    if (argc == 1)
    {
        cout << "Please add a parameter" << endl;
        return 0;
    }

    string userCommand = string(argv[1]);
    if (userCommand == "add" && argc == 3)
    {
        todoList.add(string(argv[2]), string(argv[3]));
    }
    else if (userCommand == "remove" && argc == 2)
    {
        if (!todoList.remove(string(argv[2])))
        {

        }
    }
    else if (userCommand == "printList" && argc == 1)
    {
        todoList.printTodoList();
    }
    else if (userCommand == "printDay" && argc == 2)
    {
        todoList.printDaysTasks(string(argv[2]));
    }
    else
    {
        cout << "Parameter not recognized." << endl\
             << "add {duedate} {task} : Adds a task with due date" << endl\
             << "remove {task}        : Removes task" << endl\
             << "printList            : Prints all tasks" << endl\
             << "printDay {date}      : Prints all tasks on date" << endl;
    }
    

    return 0;
}