//Copyright Wed Feb 15 21:47:29 2017, Liam Rogers, All rights reserved.

/*
 * Creates file that acknowledges owner of project.
 * CTK will look for this file everytime a new source file
 * is added to the project.
 */

#include <project/CppProject.hpp>
#include <ctk/application/terminal.hpp>

using namespace std;
using namespace workflow;

int main(int argc, char* argv[])
{
    vector<string> args = ctk::application::retrieveArgs(argc, argv);
    if (argc < 2)
    {
        cout << "copyright <owner name>" << endl;
        cout << "Creates copyright file which Workflow will look for whenever a new source/module" << endl;
        cout << "is added to the project." << endl;
    }
    else
    {
        project::CppProject project;
        string owner(args.at(1));
        project.initCopyright(owner);
        cout << "Initialised copyrights for " << owner << endl;
    }


}
