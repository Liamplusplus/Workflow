// Copyright 2016, Liam Rogers, All rights reserved.

#include <project/CppProject.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace workflow;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "branch <NAME>" << endl;
        cout << "workflow will initialise branch for appropriate directories." << endl;
    }
    else
    {
        string branch(argv[1]);
        cout << "Creating branch: " << branch << endl;

        project::CppProject project;
        project.createBranch(branch);

        cout << "Created branch " << branch << " in " << project.getName() << endl;
        cout << "Make sure to add " << branch << " to your makefile" << endl;
    }
    return 0;
}
