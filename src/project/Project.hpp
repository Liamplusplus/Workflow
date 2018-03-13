/*
 * Description: 
 * 
 * Base project class for integrated development environments
 * Consider refactoring this branch to a seperate library as
 * this doesn't really serve purpose as a generic tool.
 *
 */

/*
 * Planned Features:
 *
 */

#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/filesystem.hpp>
#include <ctk/file/utility.hpp>
#include <ctk/log/GlobalLogger.hpp>

namespace workflow { namespace project {

    class Project 
    {
        public:

            Project(string dir = "./"); 
            /*
             * Class needs to store the path to the
             * project directory from the cwd for 
             * filesystem functions
             * 
             * If no destination directory is given, program
             * will assume current shell directory as program
             * directory
             *
             * Owner name is used to generate copyright messages 
             * on source and claim intellectual property
             */

            virtual void initialise() = 0;
            /*
             * Example if running from command line: 
             * CppProject p1("pathtoproject/projectname/");
             * p1.initialise(); 
             */    

            void setCopyright(string inName);
            string& getName()       { return name; }
            string& getCopyrightHolder()       { return copyright_holder; }

        protected:

            string name;
            string copyright_holder;
            bool copyright;
            
            string directory;
            /*
             * Path from cwd in terminal or executable
             * to the target project dir
             */



    };

}}
