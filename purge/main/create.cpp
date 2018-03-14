
/*
 * create: Creates a c++ cpp/hpp bundle.
 * if no branch is given, placed directly in src/
 * Added class template generation should be a feature,
 * not the program.
 * Adding all .hpps to include/ should be a seperate function
 */

#include <iostream>
#include <string>

#include <ctk/application/terminal.hpp>
#include <project/CppProject.hpp>
#include <ctk/algorithm.hpp>

using namespace std;
using namespace workflow::project;

int main(int argc, char* argv[])
{
    vector<string> args = ctk::application::retrieveArgs(argc, argv);
    bool isClass = ctk::algorithm::contains(args.begin(), args.end(), string("-class"));

    if (argc < 2)
    {
        cout << args.at(0) << " <name>"<< endl;
        cout << "Optional: <-b branch> [-class]" << endl;
    }
    else 
    {
        string branch = ctk::algorithm::after(args.begin(), args.end(), string("-b"));
        string classname(args.at(1));
        cout << "Creating class: " << classname;
        cout << " for branch " << branch << endl;
        CppProject temp;
        temp.createBranch(branch);
        temp.generateTemplate(classname, isClass, branch);
    }
    return 0;
}



