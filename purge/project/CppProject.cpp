#include <project/CppProject.hpp>
#include <stdlib.h>
#include <array>

using namespace std;
using namespace ctk::log;

namespace workflow { namespace project {

    CppProject::CppProject(string dir) : Project(dir) 
	{

	}

    /*
     * Initialise project
     * CppProject project("path/to/valid/directory/name");
     * project.initialise();
     */
	void CppProject::initialise()
	{
		GlobalLogger::log(EXTERNAL) << "Initialising C++ project with name: " << name << " at directory " << directory <<  Sentinel::END;
        path dir(directory);
        if (exists(dir))
		{
            GlobalLogger::log(EXTERNAL) << name << " already exists in this directory!" << Sentinel::END;
		}
        else
		{
            GlobalLogger::log(EXTERNAL) << "Creating project directory" << Sentinel::END;

            create_directory(dir);

            std::array<std::string, 3> toolchains{ "gcc", "mingw32", "mingw64" };
            create_directory(directory + "bin");
            create_directory(directory + "lib");
            for (auto& it : toolchains)
            {
                create_directory(directory + "bin/" + it);
                create_directory(directory + "bin/" + it + "/optimized");
                create_directory(directory + "bin/" + it + "/test");
                create_directory(directory + "lib/" + it);
                create_directory(directory + "lib/" + it + "/optimized");
            }

            std::array<std::string, 3> targets{ "linux", "w32", "w64" };
            create_directory(directory + "release");
            for (auto& it : targets)
            {
                create_directory(directory + "release/" + name + "-" + it);
            }

            create_directory(directory + "doc");
            create_directory(directory + "log");
            create_directory(directory + ".resources");
            string source(directory + "src");
            create_directory(source);
            create_directory(source + "/main");
            create_directory(source + "/test");
            generateMakeFile(); 
		}
    }
    
    void CppProject::generateMakeFile()
    {
        string env(std::getenv("WORKFLOW"));
        path mk(env + "/config/maketemplate");
        GlobalLogger::log(INFO) << "Fetching maketemplate from " << mk << Sentinel::END; 
        copy_file(mk, path(directory + "makefile"));
    }

    void CppProject::generateMain(string name, bool test)
    {
        string dir(directory + "src/");
        if (test)
            dir += "test/";
        else
            dir += "main/";

        string file(dir + name + ".cpp");
        std::fstream main(file.c_str(), ios_base::app);

        if (is_directory(path(dir)))
        {
            GlobalLogger::log(EXTERNAL) << "Creating C++ main implementation: " << name << " in branch " << dir;

            main << endl << "int main(";
            main << "int argc, char* argv[]";
            main << ")" << endl << "{" << endl << endl << "}";
        }
        else
        {
            GlobalLogger::log(EXTERNAL) << "Tried to create C++ main implementation " << name << " but " << dir << " does not exist." << Sentinel::END;
        }
    }

    void CppProject::generateCopyright(std::fstream& inStream)
    {
            path cw(directory + ".copyright");
            if (exists(cw))
            {
                string line;
                std::ifstream ifs(cw.string().c_str());
                std::getline(ifs, line);
                copyright_holder = line; 

                GlobalLogger::log(EXTERNAL) << "Generating copyright for owner: " << copyright_holder << Sentinel::END; 
                std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
                std::time_t now_time = std::chrono::system_clock::to_time_t(now);
                inStream  << "// Copyright " << std::ctime(&now_time) << "// " << copyright_holder << ", All rights reserved." << endl << endl;
            }
    }

    void CppProject::initCopyright(string owner)
    {
        string cw(directory + "..copyright");
        std::fstream fs(cw.c_str(), ios_base::app);
        fs << owner;
    }

    void CppProject::generateTemplate(const string& name, bool isClass, string branch)
    {
        path srcbranch(directory + "src/" + branch); 

        if (is_directory(srcbranch))
        {
                generateSource(srcbranch.string() + "/" +  name, isClass);
                generateHeader(srcbranch.string() + "/" + name, isClass);
        }
        else
        {
            GlobalLogger::log(EXTERNAL) << "Tried to create class " << name << " in branch " << branch;
            GlobalLogger::log(EXTERNAL) << " but " << srcbranch.string() << " does not exist" << Sentinel::END;
            GlobalLogger::log(EXTERNAL) << " Try: branch  " << branch << Sentinel::END;
        }
        if (isLibrary())
        {
        path incbranch(directory + "include/" + this->name + "/" + branch);
        if (is_directory(incbranch))
            generateHeader(incbranch.string() + "/" + name, isClass);
        else
            GlobalLogger::log(EXTERNAL) << incbranch.string() << " not found, not generating branch header" << Sentinel::END;
        }

        GlobalLogger::log(EXTERNAL) << "Successfully created " << name << " C++ template" << Sentinel::END;
    }


    void CppProject::generateHeader(const string& path, bool isClass)
    {
        boost::filesystem::path h(path + ".hpp");
        string classname = boost::filesystem::path(path).filename().string();
    
        if (exists(h))
        {
            GlobalLogger::log(EXTERNAL) << "Tried to generate header that already exists " << h.string() << Sentinel::END;
        }
        else
        {
            std::fstream header(h.string(), ios_base::app);
            generateCopyright(header);
            header << "/*\n * File description\n */\n\n#pragma once\n" << endl;
            header << "namespace " << name << " { namespace "; 
            header << h.parent_path().filename().string() << " {" << endl << endl; 
            if (isClass)
            {
                header << "\tclass " << classname << "\n\t{\n\t\tpublic:\n\n\t\t\t" << classname;
                header << "();\n\t\t\t~" << classname << "();";
                header << "\n\n\t};";
            }

            header << "\n\n}}";
            GlobalLogger::log(EXTERNAL) << "Successfully created header " << h.string() << Sentinel::END;
        }
    }
/*
 * Generate branch.hpp, directory given by generate class function
 */ void CppProject::generateBranchHeader(const string& path)
    {
        boost::filesystem::path h(path + ".hpp");
        if (exists(h))
        {
            GlobalLogger::log(EXTERNAL) << "Tried to generate branch header that already exists " << h.string() << Sentinel::END;
        }
        else
        {
            std::fstream header(h.string(), ios_base::app);
            header << "/* \n * Branch description\n */\n\n#pragma once";
        }
    }

/*
 * Generate classname.cpp, directory given by generate class function
 */void CppProject::generateSource(const string& path, bool isClass)
    {
        string classname = boost::filesystem::path(path).filename().string();
        boost::filesystem::path src(path + ".cpp");
        if (exists(src))
        {
            GlobalLogger::log(EXTERNAL) << "Tried to generate source file that already exists " << src.string() << Sentinel::END;
        }
        else 
        {
            std::fstream source(src.string(), ios_base::app);
            generateCopyright(source);
            source << "#include \"" << classname << ".hpp\"" << "\n\n\n"; 
            source << "namespace " << name << " { namespace "; 
            source << src.parent_path().filename().string() << " {" << endl << endl;
            if (isClass)
            {
                source << "\t" << classname << "::" << classname << "()\n\t{\n\t}\n\n"; 
                source << "\t" << classname << "::~" << classname << "()\n\t{\n\t}" << endl;
            }
            source << "\n}}" << endl; 
            GlobalLogger::log(EXTERNAL) << "Successfully created source file " << src.string() << Sentinel::END;
        }
    }

/*
 * Creates a directory "name" in src/
 * Different behaviours for programs and libraries
 * Libraries create branch in /include/proj/ and src/
 * where programs only target src/
 */ void CppProject::createBranch(string& inName)
    {
        path srcbranch(directory + "src/" + inName);
        
        if (exists(srcbranch))
        {
            GlobalLogger::log(EXTERNAL) << "Tried to create branch " << srcbranch.string() << "but already exists" << Sentinel::END;
        }
        else
        {
            create_directory(srcbranch);
            path incbranch(directory + "include/" + name + "/" + inName);

            if (isLibrary() && !(is_directory(incbranch)))
            {
                create_directory(incbranch);
                generateBranchHeader(incbranch.string());
            }
            else
            {
                generateBranchHeader(srcbranch.string());
            }
        }
    }

    bool CppProject::isLibrary()
    {
        return is_directory(directory + "include");
    }

    void CppProject::transferHeaders()
    {
        path target(directory + "src/");
        path dest(directory + "include/" + name + "/");
        path include(directory + "include");
        if (!is_directory(include))
            create_directory(include);
        if (!is_directory(dest))
            create_directory(dest);
        ctk::file::copyExt(target, dest, ".hpp");
    }

}} 

