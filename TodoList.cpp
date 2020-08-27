#pragma once

#include "TodoList.h"
#include <fstream>
#include <vector>

using namespace std;

TodoList::TodoList()
    : TodoListInterface()
{
    fileName = "TODOList.txt";
    ifstream file(fileName);

    while (getline(file, currentLine))
    {
        dates.push_back(currentLine);
        getline(file, currentLine);
        tasks.push_back(currentLine);
    }

    file.close();
}

TodoList::~TodoList()
{
    ofstream file(fileName);
    for (size_t i = 0; i < dates.size(); i++)
    {
        file << dates.at(i) << endl;
        file << tasks.at(i) << endl;
    }
    file.close();
}


void TodoList::add(string _duedate, string _task)
{
    dates.push_back(_duedate);
    tasks.push_back(_task);
}

int TodoList::remove(string _task)
{
    for (size_t i = 0; i < tasks.size(); i++)
    {
        if (_task == tasks.at(i))
        {
            tasks.erase(tasks.begin() + i);
            dates.erase(tasks.begin() + i);
            return i;
        }
    }
}

void TodoList::printTodoList()
{
    for (size_t i = 0; i < dates.size(); i++)
    {
        cout << dates.at(0) << endl;
        cout << tasks.at(0) << endl;
    }
}

void TodoList:: printDaysTasks(string _date)
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