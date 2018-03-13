/*
 * Description:
 *
 * Automate common functions
 * All function should check for exceptions
 * like creating existing directories so anyone can call
 * them
 *
 */

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <ctk/file/utility.hpp>
#include <project/Project.hpp>

using std::string;
using namespace boost::filesystem;

namespace workflow { namespace project {

    class CppProject : public workflow::project::Project
    {
        public:

            CppProject(string dir = "./");
            /*
             * eg CppProject project("<path/name>")
             *    project.initialise();
             *
             * or CppProject project; //already initialised in current dir
             *    project.generateTemplate("Enemy", true, "Entity");
             */

            void initialise();
            void initialiseTestDirectories();
            void generateMain(string name, bool test = false);

            /*
            * Run from inside the project directory
            */ 
            void generateTemplate(const string& name, bool isClass, string branch);
            void generateSource(const string& path, bool isClass);
            void generateHeader(const string& path, bool isClass);
            void generateBranchHeader(const string& path);

            void createBranch(string& name);

            void transferHeaders();
            void prepareRelease(string target);
            bool isLibrary();
            
            void initCopyright(string owner);
            /*
             * Generates hidden file in directory .copyright
             * so every source file can use owners name
             */

        protected:

            void generateMakeFile();
            void generateCopyright(std::fstream& inStream);
    };

}}

