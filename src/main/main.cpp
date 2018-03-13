//© Copyright 2016, Liam Rogers, All rights reserved.

#include <ctk/application/terminal.hpp>
#include <project/CppProject.hpp>
#include <ctk/algorithm/algorithm.hpp>

#include <iostream>
#include <string>

using namespace std;
using namespace ctk;
using namespace workflow;

int main(int argc, char* argv[])
{
    vector<string> args(application::retrieveArgs(argc,argv));
    if (argc < 2)
    {
        cout << "main <name> [Optional -t]" << endl;
        cout << "Creates new implementation file inside ./src/[main/test]/ directory" << endl;
    }
    else
    {
        string name(args.at(1));
        project::CppProject project;
        bool test = algorithm::contains(args.begin(), args.end(), "-t");
        project.generateMain(name, test);
        cout << "Generated new " << name << ".cpp implementation for " << project.getName() << endl;
    }

}
