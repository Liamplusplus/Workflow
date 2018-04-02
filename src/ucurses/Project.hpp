
#pragma once
#include "MainUI.hpp"
#include <vector>

class Project
{
    public:

        void Build();

    protected:

        void loadConfiguration();

        std::vector<std::string> dependancies;      /* Passed to LIBFILES variable in make */
        std::vector<std::string> modules;           /* Passed to BRANCHES variable in make */
        std::vector<std::string> classes;           /* Passed to SRC variable in make */
        std::string name;

        MainUI main_ui;


};
