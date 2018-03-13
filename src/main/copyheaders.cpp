//Copyright 2016, Liam Rogers, All rights reserved.

#include <project/CppProject.hpp>

using namespace workflow::project;

int main(int argc, char* argv[])
{
    CppProject project;
    project.transferHeaders();
    cout << "Finished recursive copy of all headers for " << project.getName() << endl;
    return 0;
}
