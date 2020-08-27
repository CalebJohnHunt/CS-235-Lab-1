#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "TodoListInterface.h"

using namespace std;


class TodoList : public TodoListInterface
{
public:
    // Constructor. Reads in the file and saves the dates and tasks to vectors
    TodoList()
        : TodoListInterface()
    {
        fileName = "TODOList.txt";
        file.open(fileName);

        // If we can get another line from the file, then add it to the dates, then the next one to the tasks
        while (getline(file, currentLine))
        {
            dates.push_back(currentLine);
            getline(file, currentLine);
            tasks.push_back(currentLine);
        }

        file.close();
    }

    // Deconstructor. Writes the dates and tasks vectors into file.
    ~TodoList()
    {
        file.open(fileName, ios::out); // ios::out causes it to completely rewrite the file (not just append)

        for (size_t i = 0; i < dates.size(); i++)
        {
            file << dates.at(i) << endl;
            file << tasks.at(i) << endl;
        }

        file.close();
    }

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    void add(string _duedate, string _task)
    {
        dates.push_back(_duedate);
        tasks.push_back(_task);
    }

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    int remove(string _task)
    {
        for (size_t i = 0; i < tasks.size(); i++)
        {
            if (_task == tasks.at(i))
            {
                tasks.erase(tasks.begin() + i);
                dates.erase(dates.begin() + i);
                return 1;
            }
        }
        return 0;
    }

    /*
    *   Prints out the full todo list to the console
    */
   void printTodoList()
    {
        for (size_t i = 0; i < tasks.size(); i++)
        {
            cout << tasks.at(i) << endl;
        }
    }
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    void  printDaysTasks(string _date)
    {
        cout << "Showing tasks for " << _date << endl;
        
        for (size_t i = 0; i < dates.size(); i++)
        {
            if (_date == dates.at(i))
            {
                cout << tasks.at(i) << endl;
            }
        }
    }

private:
    string currentLine; // Temporary variable used with getline() to read file
    string fileName;
    fstream file;
    vector<string> dates;
    vector<string> tasks;
};