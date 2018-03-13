/*
 *  Initialise Cpp project
 *  Passing -t [path] will provide 
 *
 */

#include <ctk/algorithm.hpp>
#include <ctk/application/terminal.hpp>
#include <project/CppProject.hpp>

#include <iostream>
#include <string>

using namespace std;
using namespace workflow;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << argv[0] << " [name]" << endl;
        cout << "Creates project titled [name] in current directory" << endl;
    }
    else
    {
        vector<string> args = ctk::application::retrieveArgs(argc,argv);
        string projectName = args.at(1);

        workflow::project::CppProject project(projectName);
        project.initialise();

        cout << "Initialised project titled " << project.getName() << endl;
    }
            
    return 0;
}

