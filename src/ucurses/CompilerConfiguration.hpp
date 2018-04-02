#pragma once
/*
 * C++ std selection / Compiler flags / Optimization level
 * Dependancies
 */

#include <ucurses/ucurses.hpp>

namespace Workflow {

    class Project;

    class CompilerConfiguration : public ucurses::State
    {
        public:

            CompilerConfiguration(Project* data);

        protected:

            // UCurses GUI setup
            void Initialize();

            ucurses::Menu* menu;
            ucurses::Label* header;
            enum Selection { STD, OPT, FLAG };

            // Workflow project data
            Project* project;

    };

}
