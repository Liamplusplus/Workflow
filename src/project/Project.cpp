#include <project/Project.hpp>

namespace workflow { namespace project {

    Project::Project(string dir) : directory(dir)
    {
        if (dir == "./")
        {
            name = current_path().filename().string();
        }
        else
        {
            name = path(directory).filename().string();
            directory += "/";
        }
        /*
         * Allows use of Project project("path/project") in constructor 
         * and create_directory(directory + "branch") in functions
         */

        GlobalLogger::log(EXTERNAL) << "Initialising base project name: " << name << " in directory " << directory << Sentinel::END;
    } 

    void Project::setCopyright(string inName)
    {
        GlobalLogger::log(EXTERNAL) << "Setting copyright holder to " << inName << Sentinel::END;
        copyright_holder = inName;
        copyright = true;
    }

}}
