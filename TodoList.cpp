#include "TodoList.h"
#include <fstream>
#include <vector>

using namespace std;

TodoList::TodoList()
    : TodoListInterface()
{
    fileName = "TODOList.txt";
    file.open(fileName);

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
    file.open(fileName, ios::out);
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
            dates.erase(dates.begin() + i);
            return 1;
        }
    }
    return 0;
}

void TodoList::printTodoList()
{
    for (size_t i = 0; i < tasks.size(); i++)
    {
        cout << tasks.at(i) << endl;
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