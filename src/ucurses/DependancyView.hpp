#pragma once
/*
 * C++ std selection / Compiler flags / Optimization level
 * Dependancies
 */

#include <ucurses/ucurses.hpp>

namespace Workflow {

    class Project;

    class DependancyView : public ucurses::State
    {
        public:

            DependancyView(Project* data);

        protected:
            
            // Workflow project data
            Project* project;

            // UCurses GUI setup
            void Initialize();

            ucurses::Menu* config_options;

            enum Selections { COMPILER_OPTIONS = 0, DEPENDANCIES, BUILD };


            // Uses default target name if empty
            ucurses::TextEntry* target_entry;

    };
}
