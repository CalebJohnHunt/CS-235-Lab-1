#include <iostream>

#include "TodoList.h"

using namespace std;

int main(int argc, char* argv[])
{
    TodoList todoList;

    // If no parameters were used, end early
    if (argc == 1)
    {
        cout << "Please add a parameter" << endl;
        return 0;
    }

    // The first parameter is the "command" the user wants
    string userCommand = string(argv[1]);

    // "Execute" the user's command. Also checks to make sure they put in the right number of parameters
    if (userCommand == "add" && argc == 4)
    {
        todoList.add(string(argv[2]), string(argv[3]));
    }
    else if (userCommand == "remove" && argc == 3)
    {
        // .remove returns 1 if successful, 0 if failed
        if (!todoList.remove(string(argv[2])))
        {
            cout << "No task of that name found. No tasks removed." << endl;
        }
    }
    else if (userCommand == "printList" && argc == 2)
    {
        todoList.printTodoList();
    }
    else if (userCommand == "printDay" && argc == 3)
    {
        todoList.printDaysTasks(string(argv[2]));
    }
    else
    {
        // If the user either entered a bad parameter or not enough, this menu will be shown
        cout << "Parameter not recognized." << endl\
             << "add {date} {task} : Adds a task with due date" << endl\
             << "remove {task}        : Removes task" << endl\
             << "printList            : Prints all tasks" << endl\
             << "printDay {date}      : Prints all tasks on date" << endl;
    }
    

    return 0;
}