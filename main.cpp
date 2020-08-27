#include <iostream>
#include <fstream>

#include "TodoList.h"

using namespace std;

class bar
{
public:
    bar(){};
    void print()
    {
        cout << "hey" << endl;
    }
};

int main(int argc, char* argv[])
{
    TodoList foo;

    if (argc == 1)
    {
        cout << "Needs more variables!" << endl;
        return 0;
    }
    string arg = string(argv[1]);
    if (arg == "add")
    {
        foo.add(string(argv[2]), string(argv[3]));
    }
    else if (arg == "remove")
    {
        foo.remove(string(argv[2]));
    }
    else if (arg == "printList")
    {
        foo.printTodoList();
    }
    else if (arg == "printDay")
    {
        foo.printDaysTasks(string(argv[2]));
    }

    return 0;
}